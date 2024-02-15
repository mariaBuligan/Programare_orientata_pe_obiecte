#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include "album.hpp"
using namespace std;


void citire(ifstream &fin,vector<Artist> &v){
    Artist aux;
    if(fin.eof())return;
    else{
     fin>>aux;
     v.push_back(aux);
     citire(fin,v);
    }
}

void afisare(vector<Artist> v){
  for(auto i=v.begin();i!=v.end();i++)cout<<*i;
}

void afisare2(vector<Artist> v,ofstream &fout){
  for(auto i=v.begin();i!=v.end();i++)fout<<*i;
}

void adauga_album(vector <Artist> &v,int nr,int an, string nume, vector<Track> p,string artist){

      for(auto i=v.begin();i!=v.end();i++){
        if(i->getNume() == artist ){
          i->set_abm(nr,an,nume,p);
          break;
        }
      }
}

void sterge_album(vector <Artist> &v,string nume_album,string artist){
        for(auto i=v.begin();i!=v.end();i++){
          if(i->getNume() == artist){
            i->erase_abm(nume_album);
            break;
        }}
}


int main(){

  vector <Artist> v;
  ifstream fin("music.txt");
  ofstream fout("output.txt");
  citire(fin,v);

  vector<Track> x;
  x.push_back(Track(1,2.13,"Blank Space"));
  x.push_back(Track(5,3.45,"Out of the woods"));
  x.push_back(Track(6,2.54,"This love"));
  x.push_back(Track(3,3.13,"Welcome to New York"));
  adauga_album(v,4,2015,"1989",x,"Taylor Swift");
  //sterge_album(v,"Speak Now","Taylor Swift");
  ordonare_abm(v);
  afisare2(v,fout);

  vector <Pers*> p;
  p.push_back(new Pers("Elena",21));
  p.push_back(new Artist(v[0]));

  cout<<typeid(p[0]).name()<<" "<<typeid(p[1]).name()<<endl;
  cout<<typeid(*p[0]).name()<<" "<<typeid(*p[1]).name()<<endl;

  vector <Pers> p2;
  p2.push_back(Pers("Elena",21));
  p2.push_back(Artist(v[0]));

  cout<<typeid(p2[0]).name()<<" "<<typeid(p2[1]).name()<<endl;

  for( auto it:p2){
     it.afis();
  }
}