#include <iostream>
#include "PointSet.h"
using namespace std;

PointSet::PointSet(int capacity)
{
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  cout << "Initialized by PointSet's conversion constructor" << endl;

  // TODO #1: add your code here
  this-> points = new Point[capacity];
  this-> capacity = capacity;
  this-> numPoints = 0;
}

PointSet::PointSet(const Point points[], int numPoints)
{
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  cout << "Initialized by PointSet's other constructor" << endl;

  // TODO #2: add your code here
  this-> points = new Point[numPoints];
  for(int i = 0; i<numPoints; i++)
      this->points[i] = points[i]; 

  this-> capacity = numPoints;
  this->numPoints = numPoints;
  
}

PointSet::PointSet(const PointSet& s)
{
  // This cout statement is for learning purpose only, which shows when the constructor will be invoked
  cout << "Initialized by PointSet's copy constructor" << endl;

  // TODO #3: add your code here
  this->points = new Point[s.capacity];
  for(int i = 0; i<s.numPoints;i++)
      this->points[i] = s.points[i];
  this->capacity = s.numPoints;
  this->numPoints = s.numPoints;
}

PointSet::~PointSet()
{
  // TODO #4: add your code here
  delete [] this->points;
}

void PointSet::addPoint(const Point& p)
{
  // TODO #5: add your code here
  if(this->numPoints < this->capacity)
      {
        this->points[numPoints] = p;
        numPoints++;
      }
  else
    cout << "Insufficient array space" << endl;

}

void PointSet::removeLastPoint()
{
  // TODO #6: add your code here
  if(this->numPoints != 0)
      numPoints--;
      
  else
    cout << "No points" << endl;

}

// Return true if the all the points in the point set is collinear; return false otherwise
bool PointSet::isCollinear() const
{
  // TODO #7: add your code here
  if(this->numPoints <= 2)
      return true;

  for(int i = 0; i < numPoints-2;i++)
    {
      if(!isCollinear_3points(this->points[i],this->points[i+1],this->points[i+2]))
        return false;
    }

  return true;
}

// return true if 3 given points are on the same straight line
bool PointSet::isCollinear_3points(const Point p1, const Point p2, const Point p3) const
{
  // TODO #8: add your code here
  float Area = (0.5) * (p1.getX()*(p2.getY()-p3.getY()) + p2.getX()*(p3.getY()-p1.getY()) + p3.getX()*(p1.getY()-p2.getY()) );
  return (Area == 0);
}

void PointSet::print() const
{
  // This function is already completed.
  if (numPoints == 0) {
    cout << "The PointSet is empty!" << endl;
    return;
  }
  cout << "Number of points: " << numPoints << endl;;
  cout << "points: " << endl;
  for(int i = 0; i < numPoints; i++)
  {
    points[i].print();
    cout << endl;
  }
}
