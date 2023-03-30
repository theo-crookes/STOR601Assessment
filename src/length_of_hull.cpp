#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include<cmath>

#include<Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
double length_of_hull(std::vector<std::vector<double>> convex_hull) // computes the length of the hull (travelling around the hull until you return to the start)
{
    int n;
    n = convex_hull.size();
    std::vector<double> lengths(n);
    double changeXsqrd;
    double changeYsqrd;
    double dist_xy {0};
    
    for(int i=0; i<n; i++)
    {
        changeXsqrd = pow(convex_hull[i][0]-convex_hull[i][2],2);
        changeYsqrd = pow(convex_hull[i][1]-convex_hull[i][3],2);
        dist_xy = pow(changeXsqrd+changeYsqrd,0.5); // the distance between the i'th and i+1'th point
        lengths[i] = dist_xy; // stores the distance found
    }
    
    double output {0};
    
    for(int i; i<n; i++)
    {
        output = output + lengths[i]; // sums over all the distances on the connected graph (the hull)
    }
    
    return output;
}
