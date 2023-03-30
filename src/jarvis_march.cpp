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
std::vector<std::vector<double> > jarvis_march(std::vector<std::vector<double> > data) //jarvis march algorithm on a vector of vector of doubles
{
    // the data has length n = data.size()
    // next we find the leftmost point in the data (smallest x coordinate) using a for loop
    // we also make sure that this is the leftmost point with the smallest y coordinate to ensure that the algorithm
    // will be consistent with regard to collinearity. If 3 or more points on the hull would be collinear, we only
    // want to choose the first and the last in the line. Choosing the starting point to be the point with the smallest
    // y coordinate among the points with all the smallest x coordinates ensures this will occur with regard to the 
    // first point. 
    
    int start_index {0};
    
    for(int i = 0; i < data.size(); i++)
    {
            if(data[i][0] == data[start_index][0])
            {
                if(data[i][1] < data[start_index][1])
                {
                    start_index = i;
                }
            }
            else if (data[i][0] < data[start_index][0])
            {
                start_index = i;
            }
    }
    
    // pick a candidate point to move to
    
    int candidate_index;
    
    if(start_index == data.size()-1) // if the start point of the hull found is the final data point, set the new candidate point to be the first data point
    {
        candidate_index = 0;
    }
    else
    {
        candidate_index = data.size()-1;
    }
    
    for(int i = 0; i < data.size(); i++)
    {
        if(i != start_index) // this ensures that we do not try to consider adding again the start index into the convex hull
        {
            double distanceValue1;
            distanceValue1 = pow(pow(data[start_index][0]-data[candidate_index][0],2)+pow(data[start_index][1]-data[candidate_index][1],2),0.5);
            double distanceValue2;
            distanceValue2 = pow(pow(data[start_index][0]-data[i][0],2)+pow(data[start_index][1]-data[i][1],2),0.5);
            
            double number1;
            double number2;
            double anon;
            number1 = (data[start_index][0]-data[candidate_index][0])*(data[start_index][1]-data[i][1]);
            number2 = (data[start_index][1]-data[candidate_index][1])*(data[start_index][0]-data[i][0]);
            anon = number1 - number2;

            if(anon == 0) // if the points are collinear
            {
                if(distanceValue1 < distanceValue2) // and if the point i is further from the start point than the candidate point
                {
                    candidate_index = i; // changes the candidate point to the new point found furthest to the right which is also collinear to the previous candidate point
                }
            }
            
            if(anon < 0) 
            {
                candidate_index = i; // changes the candidate point to the new point found furthest to the right
            }
            
            
        }
    }
    
    std::vector<std::vector<double>> convex_hull {data[start_index]}; // this will be a list containing the points of the convex hull in the output
    // we will append to this list as we find a new point in the hull
    
    int recent_index {candidate_index};
    
    while(recent_index != start_index)
    {
        // append the most recent point found on the hull to the hull list
        // we do this at the start of the while loop (and not the end) to ensure the start index is not added
        convex_hull.push_back(data[recent_index]);
        
        // pick a new candidate point (different from the most recent point found on the hull)
        if (recent_index == data.size()-1) // if the recent point of the hull found is the final data point, set the new candidate point to be the first data point
        {
            candidate_index = 0;
        }
        else
        {
            candidate_index = data.size()-1;
        }
        
        
        for(int i = 0; i < data.size(); i++)
        {
            if(i != recent_index) // this ensures that we do not try to consider adding again the start index into the convex hull
            {
                double distanceValue1;
                distanceValue1 = pow(pow(data[recent_index][0]-data[candidate_index][0],2)+pow(data[recent_index][1]-data[candidate_index][1],2),0.5);
                double distanceValue2;
                distanceValue2 = pow(pow(data[recent_index][0]-data[i][0],2)+pow(data[recent_index][1]-data[i][1],2),0.5);
            
                double number1;
                double number2;
                double anon;
                number1 = (data[recent_index][0]-data[candidate_index][0])*(data[recent_index][1]-data[i][1]);
                number2 = (data[recent_index][1]-data[candidate_index][1])*(data[recent_index][0]-data[i][0]);
                anon = number1 - number2;

                if(anon == 0) // if the points are collinear
                {
                    if(distanceValue1 < distanceValue2) // and if the point i is further from the start point than the candidate point
                    {
                        candidate_index = i; // changes the candidate point to the new point found furthest to the right which is also collinear to the previous candidate point
                    }
                }
            
                if(anon < 0) 
                {
                    candidate_index = i; // changes the candidate point to the new point found furthest to the right
                }
            }
        }
        
        recent_index = candidate_index; // the new recent point of the next iteration of the while loop is the most recent point of the convex hull that has been found             
    }
    
    //std::list<std::vector<double> > output;
    
    //int k;
    //k = convex_hull.size();
    //for(int j = 0; j<k; j++)
    //{
    //    output.push_back(convex_hull[j]);
    //}
    
    int n;
    n = convex_hull.size();
    std::vector<std::vector<double> > result(n);
    std::vector<double> update(4); // this vector will be updated frequently
    
    
    for(int i = 0; i < n-1; i++)
    {
        update[0] = convex_hull[i][0];
        update[1] = convex_hull[i][1];
        update[2] = convex_hull[i+1][0];
        update[3] = convex_hull[i+1][1];
        result[i] = update; // makes sure the output has the desired structure
    }    
    
    update[0] = convex_hull[n-1][0];
    update[1] = convex_hull[n-1][1];
    update[2] = convex_hull[0][0];
    update[3] = convex_hull[0][1];
    result[n-1] = update; // completes the final step, making sure the output has the desired structure
    
    return result;
}
