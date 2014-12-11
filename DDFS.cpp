#include "DDFS.h"
#include <climits>
#include <iostream>
#include <algorithm>    // std::reverse

DDFS::DDFS() {


firstTravelIteration = true;
}

void DDFS::createDataVector(string city)
{
  startingCity = city;
  for(int i =0; i < departureNodes.size(); i++)
    {
      data d;
      d.cumulativeTime = INT_MAX;
      if(departureNodes[i].CityName == startingCity)
	{	//It takes 0 minutes/dollars/hops to get to from starting city to starting city
	  d.cumulativeTime = 0;
	}
      d.currentCity = departureNodes[i].CityName;
      d.previousCity = "";
      dataVector.push_back(d);
    }
  
}

void DDFS::addFlight(Flight newFlight) {
	int i = 0;
	bool duplicate = false;
	string newDepartCityName = newFlight.departureCity;
	for (i; i < departureNodes.size(); i++) {
		if (departureNodes[i].CityName == newDepartCityName) {
			duplicate = true;
			break;
		}
	}
	if (duplicate) {
		departureNodes[i].addFlight(newFlight);
	}
	else {
		DepartNode newDepartureNode;
		newDepartureNode.setCityName(newDepartCityName);
		newDepartureNode.addFlight(newFlight);
		departureNodes.push_back(newDepartureNode);
	}

}

void DDFS::JustGetMeThereToday(string start, string prevCity, string dest, int currentTime)
{
		
	if(firstTravelIteration == true)	//dont increment time for first iteration, no traveling done
	{
	  startingTime = currentTime;
	  startingCity = start;
		destinationCity = dest;
		iti = 'J';
	//	cout << "you want to go from " << start <<endl << "to " << dest << endl << " you want all flights to be after : " << currentTime << "minutes before midnight" << endl;
		if(start == dest)
		{
		cout << "Error: You're already there... " << endl;
		return;
		}
	


		firstTravelIteration = false;
		prevCity = start;
		cout << "Current Time" << currentTime << endl;
		for(int i = 0; i < departureNodes.size(); i++)
		{
			if(departureNodes[i].CityName == start)   //find corresponding departure node
			{
				for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
				{
					JustGetMeThereToday(departureNodes[i].DestinationList[j].CityName, prevCity, dest, currentTime);

				}
			}
		}
	} 
	
	else				
	{




		for(int i = 0; i < departureNodes.size(); i++)
					{
						if(departureNodes[i].CityName == prevCity)   //find corresponding departure node
						{
						  cout << "Current Time" << currentTime << endl;
						currentTime = departureNodes[i].nextFlight(start, currentTime).destinationTime.timeInt;	

						if(currentTime > (24*60)) //reached the next day
						{
						cout << "No flights to get you there that day" << endl;
						return;
						
						}
						//find a flight flight from prevCity to start and increment


						}
					}

	

		for(int i = 0; i < dataVector.size(); i++)
		{
		if(dataVector[i].currentCity == start)	//find the corresponding data for this city
			{
			if(dataVector[i].cumulativeTime > currentTime) //if it's faster
				{
				dataVector[i].cumulativeTime = currentTime; //update data
				dataVector[i].previousCity = prevCity;
				if(start != dest)
				{
				for(int k = 0; k < departureNodes.size(); k++)
					{
						if(departureNodes[k].CityName == start)   //find corresponding departure node
						{
							for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
							{
								JustGetMeThereToday(departureNodes[k].DestinationList[j].CityName, start, dest, currentTime);
							}
						}
					}
				}

				}
			}
		}
	
    }
    
}

void DDFS::FewestHops(string start, string prevCity, string dest, int currentTime, int hops)
{
	if(firstTravelIteration == true)	//dont increment time for first iteration, no traveling done
	{
	  startingTime = currentTime;
	  startingCity = start;
		destinationCity = dest;
		iti = 'F';
		hops = 0;
		if(start == dest)
		{
		cout << "Error: You're already there... " << endl;
		return;
		}
		firstTravelIteration = false;
		prevCity = start;
	
		for(int i = 0; i < departureNodes.size(); i++)
		{
			if(departureNodes[i].CityName == start)   //find corresponding departure node
			{
				for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
				{
					FewestHops(departureNodes[i].DestinationList[j].CityName, prevCity, dest, currentTime, hops);
					
				}
			}
		}
	} 
	

	else				
	{



		for(int i = 0; i < departureNodes.size(); i++)
					{

						if(departureNodes[i].CityName == prevCity)   //find corresponding departure node
						{


//						currentTime = departureNodes[i].nextFlightAnyTime(start, currentTime).destinationTime.timeInt;
	Flight f;
	f =  departureNodes[i].nextFlightAnyTime(start, currentTime %1440);
	int temp = f.destinationTime.timeInt - (currentTime % 1440);

	if(temp >= 0)
	{
	currentTime += temp;			
	}	
	else
	{
		currentTime  += 1440 - currentTime % 1440;
		currentTime += f.destinationTime.timeInt;
	}
				hops= hops+1;		



						}
					}

	

		for(int i = 0; i < dataVector.size(); i++)
		{
		if(dataVector[i].currentCity == start)	//find the corresponding data for this city
			{
			if(dataVector[i].cumulativeTime > hops) //if has less hops
				{
				dataVector[i].cumulativeTime = hops; //update data
				dataVector[i].previousCity = prevCity;
				if(start != dest)
				{
				for(int k = 0; k < departureNodes.size(); k++)
					{
						if(departureNodes[k].CityName == start)   //find corresponding departure node
						{
							for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
							{
								FewestHops(departureNodes[k].DestinationList[j].CityName, start, dest, currentTime, hops);
							}
						}
					}
				}

				}
			}
		}
	
    }
    
}

void DDFS::ShortestTrip(string start, string prevCity, string dest, int currentTime)
{
 
		
	if(firstTravelIteration == true)	//dont increment time for first iteration, no traveling done
	{
	  startingTime = currentTime;
		startingCity = start;
		destinationCity = dest;
		iti = 'S';
		
		if(start == dest)
		{
		cout << "Error: You're already there... " << endl;
		return;
		}
	


		firstTravelIteration = false;
		prevCity = start;
	
		for(int i = 0; i < departureNodes.size(); i++)
		{
			if(departureNodes[i].CityName == start)   //find corresponding departure node
			{
				for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
				{
					ShortestTrip(departureNodes[i].DestinationList[j].CityName, prevCity, dest, currentTime);

				}
			}
		}
	} 
	
	else				
	{




		for(int i = 0; i < departureNodes.size(); i++)
					{
					if(departureNodes[i].CityName == prevCity)   //find corresponding departure node
		{
		Flight f;
		f =  departureNodes[i].nextFlightCheapest(start, currentTime %1440);
		int temp = f.destinationTime.timeInt - (currentTime % 1440);

		if(temp >= 0)
		{
			currentTime += temp;			
		}	
		else
		{
			currentTime  += 1440 - currentTime % 1440;
			currentTime += f.destinationTime.timeInt;
		}
		}
					}

	

		for(int i = 0; i < dataVector.size(); i++)
		{
		if(dataVector[i].currentCity == start)	//find the corresponding data for this city
			{
			if(dataVector[i].cumulativeTime > currentTime) //if it's faster
				{
				dataVector[i].cumulativeTime = currentTime; //update data
				dataVector[i].previousCity = prevCity;
				if(start != dest)
				{
				for(int k = 0; k < departureNodes.size(); k++)
					{
						if(departureNodes[k].CityName == start)   //find corresponding departure node
						{
							for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
							{
								ShortestTrip(departureNodes[k].DestinationList[j].CityName, start, dest, currentTime);
							}
						}
					}
				}

				}
			}
		}
	
    }
    
}

void DDFS::CheapestTrip(string start, string prevCity, string dest, int currentTime, int cost)
{
 
		
	if(firstTravelIteration == true)	//dont increment time for first iteration, no traveling done
	{
		startingTime = currentTime;
		startingCity = start;
		destinationCity = dest;
		iti = 'C';
		cost = 0;
		if(start == dest)
		{
		cout << "Error: You're already there... " << endl;
		return;
		}
	


		firstTravelIteration = false;
		prevCity = start;
	
		for(int i = 0; i < departureNodes.size(); i++)
		{
			if(departureNodes[i].CityName == start)   //find corresponding departure node
			{
				for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
				{
					CheapestTrip(departureNodes[i].DestinationList[j].CityName, prevCity, dest, currentTime, cost);

				}
			}
		}
	} 
	
	else				
	{




	for(int i = 0; i < departureNodes.size(); i++)
	{
		if(departureNodes[i].CityName == prevCity)   //find corresponding departure node
		{
		Flight f;
		f =  departureNodes[i].nextFlightCheapest(start, currentTime %1440);
		int temp = f.destinationTime.timeInt - (currentTime % 1440);

		if(temp >= 0)
		{
			currentTime += temp;			
		}	
		else
		{
			currentTime  += 1440 - currentTime % 1440;
			currentTime += f.destinationTime.timeInt;
		}
				cost = cost + f.cost;		



		}

	}
					

	

		for(int i = 0; i < dataVector.size(); i++)
		{
		if(dataVector[i].currentCity == start)	//find the corresponding data for this city
			{
			if(dataVector[i].cumulativeTime > cost) //if it's cheaper
				{
				dataVector[i].cumulativeTime = cost; //update data
				dataVector[i].previousCity = prevCity;
				if(start != dest)
				{
				for(int k = 0; k < departureNodes.size(); k++)
					{
						if(departureNodes[k].CityName == start)   //find corresponding departure node
						{
							for(int j = 0; j < departureNodes[i].DestinationList.size(); j++) // travel to each one of the cities
							{
								CheapestTrip(departureNodes[k].DestinationList[j].CityName, start, dest, currentTime, cost);
							}
						}
					}
				}

				}
			}
		}
	
    }
    

}
void DDFS::setFlightVector()
{
string from;
string to;
int currentTime = startingTime.timeInt;
to = destinationCity;
 cout << "Current Time" << currentTime<< endl;;
bool first = true;

	for(int i = 0; i < dataVector.size(); i++)
	{
		//cout << to << endl;
		if(dataVector[i].currentCity == to)   //find corresponding datavector
		{	
			cout << endl << dataVector[i].currentCity << " from " << dataVector[i].previousCity << endl;


			if(first == true)
			{
			first = false;
			if(dataVector[i].previousCity == "")
			{

cout << "Error: Path from " << startingCity << " to " << destinationCity << " could not be found" << endl; 
				return;					//we never found a path
				
			}	
			}
			from = dataVector[i].previousCity;
		//cout << from << endl;
			for(int k = 0; k < departureNodes.size(); k++)
			{
				if(departureNodes[k].CityName == from)   //find corresponding departure node
				{


			cout << "looking for a flight from " << departureNodes[k].CityName << " to " << to << endl;
			cout << "adding flight------" << endl;
			//departureNodes[k].nextFlight(to, currentTime).print();
			cout << "----------------" << endl;
		
if(iti == 'J')
	{

	flights.push_back(departureNodes[k].nextFlight(to, currentTime));
	currentTime = departureNodes[k].nextFlight(to, currentTime).destinationTime.timeInt;
	}

if(iti == 'F')
	{
	

	Flight f;
	f =  departureNodes[i].nextFlightAnyTime(to, currentTime %1440);
	flights.push_back(f);
	int temp = f.destinationTime.timeInt - (currentTime % 1440);

	if(temp >= 0)
	{
	currentTime += temp;			
	}	
	else
	{
		currentTime  += 1440 - currentTime % 1440;
		currentTime += f.destinationTime.timeInt;
	}
	}
if(iti == 'S')
	{
	

	Flight f;
	f =  departureNodes[i].nextFlightAnyTime(to, currentTime %1440);
	flights.push_back(f);
	int temp = f.destinationTime.timeInt - (currentTime % 1440);

	if(temp >= 0)
	{
	currentTime += temp;			
	}	
	else
	{
		currentTime  += 1440 - currentTime % 1440;
		currentTime += f.destinationTime.timeInt;
	}
	}
if(iti == 'C')
	{
	

	Flight f;
	f =  departureNodes[i].nextFlightCheapest(to, currentTime %1440);
	cout << "f is ";
	f.print();
	flights.push_back(f);
	int temp = f.destinationTime.timeInt - (currentTime % 1440);

	if(temp >= 0)
	{
	currentTime += temp;			
	}	
	else
	{
		currentTime  += 1440 - currentTime % 1440;
		currentTime += f.destinationTime.timeInt;
	}
	}
					if(from != startingCity)
					{
						to = dataVector[i].previousCity;
						k = departureNodes.size();
						i = -1;
					}
					
				}
			}
			
		}
	}

 std::reverse(flights.begin(),flights.end());

 
//for(int i = 0; i < flights.size(); i++)
//{
//flights[i].print();
//}
}
void DDFS::printDataVector()
{
for(int i = 0; i < dataVector.size(); i++ )
{
cout << "City: " << dataVector[i].currentCity << " Time: " << dataVector[i].cumulativeTime << " Last City: " << dataVector[i].previousCity << endl;
}
}
void DDFS::printFlightVector()
{
for(int i = 0; i < flights.size(); i++)
{
	flights[i].print();
} 

}
void DDFS::print() {
	for (int i = 0; i < departureNodes.size(); i++) {
		departureNodes[i].print();
	}
}
