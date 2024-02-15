#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Pers{
    string nume;
    int age;

public:
    Pers(){ nume=string(); age=-1;};
    Pers(string n,int a){ nume=string(n); age=a; };
    ~Pers()=default;

    friend bool operator<(const Pers &v, const Pers &v2){
        return v.nume<v2.nume;
    }
    friend istream &operator>>(istream &fin, Pers &v);
    virtual void afis()const;
    string getNume()const { return nume; };
    int getAge()const{ return age;};
};



/////////////////////////////////////////////////////////////////////////////

class Track{
    int poz;
    float durata;
    string title;

public:
    Track(){poz=0;durata=0.0;title=string();};
    Track(int p,float d, string tl) {poz=p; durata=d; title=string(tl);}
    
    int getPoz(){return poz;}
    float getDur()const{return durata;}
    string getTit(){return title;}

    void setPoz(int p){poz=p;}
    void setDur (float d){durata=d;}
    void setTit(string t){title=t;}

    friend istream &operator>>(istream &fin,Track &v);
    void afis(int a,int b)const;
    
};

//////////////////////////////////////////////////////////////////////////////////

class Album{
    int nr_trk;
    int an;
    string album;
    vector <Track> songs;

public:
    Album(){nr_trk=0; an=0; album=string();};
    Album(int t,int y,vector<Track> s,string a){
        nr_trk=t; 
        an=y;
        album=a;
        songs.resize(nr_trk);
        songs=s;

    }
    Album(const Album &v){
        nr_trk=v.nr_trk;  an=v.an; album=v.album;
        songs.resize(nr_trk);
        songs=v.songs;
    }
    ~Album()=default;
    friend istream &operator>>(istream &fin, Album &v);
    string getAlbum(){ return album;}
    int getAn()const {return an;}
    void afis() const;
    void set_trk(int n){nr_trk=n;};
    void set_an(int a){an=a;};
    void set_songs(int p, float d, string t){ songs.push_back(Track(p,d,t));};
      
};

/////////////////////////////////////////////////////////////////////////////////////////////

class Artist: public Pers{
    int nr_albume;
    vector <Album> abm;

public:
    Artist():Pers(){}
    Artist(int nr,const vector<Album> al, string n, int a):Pers(n,a){
        nr_albume=nr;
        abm.resize(nr_albume);
        abm=al;
       
    }
    Artist(const Artist &v,const Pers &p):Pers(p){
        nr_albume=v.nr_albume;
        abm.resize(nr_albume);
        abm=v.abm;
    }
    ~Artist()=default;

    friend istream &operator>>(istream &fin, Artist &v);
    friend ostream &operator<<(ostream &fout, const Artist &v);
    Artist &operator=(const Artist &v);
    void afis()const;
    int getNr_Alb()const {return nr_albume;}
    void set_abm(int n,int a,string x,vector <Track> v){
        ++nr_albume;
        abm.push_back(Album(n,a,v,x));
    }
    void erase_abm(string nume_alb){
        --nr_albume;
        for(auto i=abm.begin();i!=abm.end();i++){
            if(i->getAlbum() == nume_alb ){
             i=abm.erase(i);
             break;
        }}
    }

   friend void ordonare_abm(vector <Artist> &v);
   friend void transform_abm(vector <Artist> &v);

};

