#pragma once
#include "define.h"

class Interval{
public:
    double min, max;

    Interval(): min(+INF), max(-INF){}

    Interval(double min, double max): min(min), max(max){}

    Interval(const Interval& a, const Interval& b){
        min = fmin(a.min, b.min);
        max = fmax(a.max, b.max);
    }

    bool contains(double x)const{
        return min <= x && x <= max;
    }

    bool surrounds(double x)const{
        return min < x && x < max;
    }

    double clamp(double x)const{
        if(x < min)return min;
        if(x > max)return max;
        return x;
    }

    double size() const {
        return max - min;
    }
};
