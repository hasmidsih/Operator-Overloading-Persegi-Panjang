#include "include/persegipanjang.hpp"

persegipanjang :: persegipanjang (int Xpusat, int Ypusat, int panjang, int lebar) 
{
    Xmin = Xpusat - (panjang / 2.f) ;
    Xmax = Xpusat + (panjang / 2.f) ;
    Ymin = Ypusat - (lebar / 2.f) ;
    Ymin = Ypusat + (lebar / 2.f) ;
}

bool persegipanjang :: operator == (persegipanjang& pp) 
{
    bool Xberirisan = (this->GetXmin() < pp.GetXmax()) && (pp.GetXmin() < this->GetXmax()) ;
    bool Yberirisan = (this->GetYmin() < pp.GetYmax()) && (pp.GetYmin() < this->GetYmax()) ;
    return Xberirisan && Yberirisan ;
}

    persegipanjang persegipanjang :: operator+(persegipanjang& pp) 
    {
        if(*this == pp) throw ;

        float new_Xmin, new_Xmax, new_Ymin, new_Ymax ;

        if(this->GetXmin() < pp.GetXmin()) new_Xmin = this->GetXmin() ;
        else new_Xmin = pp.GetXmin() ;

        if(this->GetXmax() < pp.GetXmax()) new_Xmax = this->GetXmax() ;
        else new_Xmax = pp.GetXmax() ;

        if(this->GetYmin() < pp.GetYmin()) new_Ymin = this->GetYmin() ;
        else new_Ymin = pp.GetYmin() ;

        if(this->GetYmax() < pp.GetYmax()) new_Xmax = this->GetYmax() ;
        else new_Ymax = pp.GetYmax() ;

        persegipanjang result(new_Xmin, new_Xmax, new_Ymin, new_Ymax) ;

        return result ; 
    }

    persegipanjang persegipanjang :: operator-(persegipanjang& pp) 
    {
        if(*this == pp) throw ;

        float new_Xmin, new_Xmax, new_Ymin, new_Ymax ;

        if(this->GetXmin() > pp.GetXmin()) new_Xmin = this->GetXmin() ;
        else new_Xmin = pp.GetXmin() ;

        if(this->GetXmax() < pp.GetXmax()) new_Xmax = this->GetXmax() ;
        else new_Xmax = pp.GetXmax() ;

        if(this->GetYmin() > pp.GetYmin()) new_Ymin = this->GetYmin() ;
        else new_Ymin = pp.GetYmin() ;

        if(this->GetYmax() < pp.GetYmax()) new_Xmax = this->GetYmax() ;
        else new_Ymax = pp.GetYmax() ;

        persegipanjang result(new_Xmin, new_Xmax, new_Ymin, new_Ymax) ;

        return result ; 
    }

    persegipanjang& persegipanjang :: operator++() 
    {
        int panjang, lebar;

        panjang = Xmax - Xmin ;
        lebar = Ymax - Ymin ;

        Xmin -= panjang / 2.f ;
        Xmax += panjang / 2.f ;
        Ymin -= lebar / 2.f ;
        Ymax += lebar / 2.f ;

        return *this ;
    }

    persegipanjang persegipanjang :: operator++(int) 
    {
        persegipanjang old = *this ;
        operator++() ;
        return old ;
    }

    persegipanjang& persegipanjang :: operator--()
    {
        int panjang, lebar ;

        panjang = Xmax - Xmin ;
        lebar = Ymax - Ymin ;

        Xmin += panjang / 4.f ;
        Xmax -= panjang / 4.f ;
        Ymin += lebar / 4.f ;
        Ymax -= lebar / 4.f ;

        return *this ;
    }

    persegipanjang persegipanjang :: operator--(int) 
    {
        persegipanjang old = *this ;
        operator--() ;
        return old ;
    }

    float persegipanjang :: operator[] (int index) 
    {
        if (index % 4 == 0) return Xmin ;
        if (index % 4 == 1) return Xmax ;
        if (index % 4 == 2) return Ymin ;
        if (index % 4 == 3) return Ymax ;
    }