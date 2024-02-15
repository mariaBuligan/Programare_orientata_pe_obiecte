#include "album.hpp"
#include <iostream>
#include <string>
using namespace std;

void Pers::afis()const{  
        cout<<endl<<nume<<" "<<age<<": "<<endl;
 }

 void Track::afis(int a,int x)const {
      if(a!=0) { for(int i=0;i<7+x;i++)cout<<" ";}
      cout<<"-> "<<title<<" "<<durata<<" "<<poz<<endl;
      a++;
 }

void Album::afis()const{
  int a=0;
   cout<<an<<" "<<album<<": ";
       for(auto i=songs.begin();i!=songs.end();i++){
           i->afis(a,album.length());
           a++;
     }
 }

void Artist::afis()const{
        Pers::afis();
         for(auto i=abm.begin();i!=abm.end();i++){
           i->afis();
        }
 }
 

Artist &Artist::operator=(const Artist &v){
      if(&v != this){
        nr_albume=v.nr_albume;
        abm.resize(nr_albume);
        abm=v.abm;
      }
        return *this;
    }

////////////////////////////////////////////////////////////

istream &operator>>(istream &fin, Pers &v){
    getline(fin>>ws,v.nume);
    fin>>v.age;

    return fin;
}

istream &operator>>(istream &fin, Track &v){
     fin>>v.poz>>v.durata;
     getline(fin, v.title);
     return fin;
     
}

istream &operator>>(istream &fin, Album &v){
        fin>>v.nr_trk>>v.an;
        getline(fin>>ws,v.album);
        
        v.songs.resize(v.nr_trk);
        for(auto i=v.songs.begin();i!=v.songs.end();i++){
           fin>>*i;
        }

     return fin;
}

istream &operator>>(istream &fin, Artist &v){
        cout<<endl;
        fin>>(Pers&)v;
        fin>>v.nr_albume;
        v.abm.resize(v.nr_albume);
       for(auto i=v.abm.begin();i!=v.abm.end();i++){
            fin>>*i;
        }
       
     return fin;

}

ostream &operator<<(ostream &fout,const Artist &v){
  fout<<"Persoana:"<<v.getNume()<<" "<<v.getAge()<<endl;

  for(auto it:v.abm){
     fout<<it.getAlbum();
  }
   return fout;
}

void ordonare_abm(vector<Artist> &v){
   for(auto i=v.begin();i!=v.end();i++){
       
       sort(i->abm.begin(),i->abm.end(),[](const Album &a, const Album &b){
            return a.getAn() < b.getAn();
       });
   }
}

/* void transform_abm(vector <Artist> &v){
  float val=1;
   for (auto i:v){
      for( auto it:i.abm){
        for(auto it2:it.songs){
            float x=it2.getDur();
            it2.setDur(x+val);
      };
   }}
} */
