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
double maximumdist(std::vector<std::vector<double>> data) // the function takes a vector of vectors of doubles (at least 2 vectors)
{
    double max_dist {0}; // initialise the maximum distance to 0
    std::vector<double> point1(2); // the first point in the pair of maximal distance (this will be updated)
    std::vector<double> point2(2); // the second point in the pair of maximal distance (this will be updated)
    double x0;
    double y0;
    double x1;
    double y1;
    double changeXsqrd;
    double changeYsqrd;
    double dist_xy;
    int n;
    n = data.size();
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n; j++)
        {
               x0 = data[i][0];
               y0 = data[i][1];
               x1 = data[j][0];
               y1 = data[j][1];
               changeXsqrd = pow(x0-x1,2);
               changeYsqrd = pow(y0-y1,2);
               dist_xy = pow(changeXsqrd+changeYsqrd,0.5);
               if(dist_xy >= max_dist) // checks to see if the newly found distance is bigger than the current maximum
               {
                   point1[0] = x0;
                   point1[1] = y0;
                   point2[0] = x1;
                   point2[1] = y1;
                   max_dist = dist_xy; // updates the new maximum distance
               }
        }    
    }
    
    double output;
    output = max_dist;
    return output; 
}

