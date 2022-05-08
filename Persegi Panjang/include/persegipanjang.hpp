#ifndef _PERSEGI_PANJANG_HPP_
#define _PERSEGI_PANJANG_HPP_

class persegipanjang{
    private:
    float Xmin, Xmax, Ymin, Ymax ;

    public:  
    persegipanjang(int Xpusat, int Ypusat, int panjang, int lebar) ;
    persegipanjang( float Xmin_ , float Xmax_ , float Ymin_ , float Ymax_ ) {Xmin = Xmin_ ; Xmax = Xmax_ ; Ymin = Ymin_ ; Ymax = Ymax_ ; }

    void SetXmin(float value) { Xmin = value ;}
    void SetXmax(float value) { Xmax = value ;}
    void SetYmin(float value) { Ymin = value ;}
    void SetYmax(float value) { Ymax = value ;}

    float GetXmin(){ return Xmin ;}
    float GetXmax(){ return Xmax ;}
    float GetYmin(){ return Ymin ;}
    float GetYmax(){ return Ymin ;}

    int Getpanjang() { return Xmax - Xmin; }
        int Getlebar() { return Ymax - Ymin; }
        int GetXpusat() { return Xmin + (Getpanjang() / 2.f); }
        int GetYpusat() { return Ymin + (Getlebar() / 2.f); }

    bool operator == (persegipanjang& pp) ;
    persegipanjang operator+(persegipanjang& pp) ;
    persegipanjang operator-(persegipanjang& pp) ;
    persegipanjang& operator++() ;
    persegipanjang operator++(int) ;
    persegipanjang& operator--() ;
    persegipanjang operator--(int) ;
    float operator[](int index) ; 
};

#endif