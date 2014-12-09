#include "DDFS.h"
#include <climits>
#include <iostream>
#include <algorithm>    // std::reverse

DDFS::DDFS() {


firstTravelIteration = true;
}

void DDFS::createDataVector()
{
cost = 0;
hops = 0;
for(int i =0; i < departureNodes.size(); i++)
{
data d;
d.cumulativeTime = INT_MAX;
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
		startingCity = start;
		destinationCity = dest;
		
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

void DDFS::FewestHops(string start, string prevCity, string dest, int currentTime)
{
 
		
	if(firstTravelIteration == true)	//dont increment time for first iteration, no traveling done
	{
		startingCity = start;
		destinationCity = dest;
		
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
						currentTime = departureNodes[i].nextFlight(start, currentTime).destinationTime.timeInt;
						hops++;		//find a flight flight from prevCity to start and increment


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

void DDFS::ShortestTrip(string start, string prevCity, string dest, int currentTime)
{
 
		
	if(firstTravelIteration == true)	//dont increment time for first iteration, no traveling done
	{
		startingCity = start;
		destinationCity = dest;
		
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
						currentTime = departureNodes[i].nextFlight(start, currentTime).destinationTime.timeInt;		//find a flight flight from prevCity to start and increment


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

void DDFS::CheapestTrip(string start, string prevCity, string dest, int currentTime)
{
 
		
	if(firstTravelIteration == true)	//dont increment time for first iteration, no traveling done
	{
		startingCity = start;
		destinationCity = dest;
		
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
						currentTime = departureNodes[i].nextFlight(start, currentTime).destinationTime.timeInt;		//find a flight flight from prevCity to start and increment

						if(currentTime > (24*60)) //reached the next day
						{

			//			return;
						
						cost+= departureNodes[i].nextFlight(start, currentTime).cost;	

						}
					}

	

		for(int i = 0; i < dataVector.size(); i++)
		{
		if(dataVector[i].currentCity == start)	//find the corresponding data for this city
			{
			if(dataVector[i].cumulativeTime > cost) //if it's faster
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
}
void DDFS::setFlightVector()
{
string from;
string to;
int currentTime;
to = destinationCity;
currentTime = 0;
bool first = false;

	for(int i = 0; i < dataVector.size(); i++)
	{
		//cout << to << endl;
		if(dataVector[i].currentCity == to)   //find corresponding datavector
		{

			if(first == false)
			{
			first = true;
			if(dataVector[i].previousCity == "")
			{
				return;					//we never found a path
				cout << "Error: Path from " << startingCity << " to " << destinationCity << " could not be found" << endl; 
			}	
			}
			from = dataVector[i].previousCity;
		//cout << from << endl;
			for(int k = 0; k < departureNodes.size(); k++)
			{
				if(departureNodes[k].CityName == from)   //find corresponding departure node
				{
					

			

			flights.push_back(departureNodes[k].nextFlight(to, currentTime));
			currentTime = departureNodes[k].nextFlight(to, currentTime).destinationTime.timeInt;
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

 
for(int i = 0; i < flights.size(); i++)
{
flights[i].print();
}
}
void DDFS::printDataVector()
{
for(int i = 0; i < dataVector.size(); i++ )
{
cout << "City: " << dataVector[i].currentCity << " Time: " << dataVector[i].cumulativeTime << " Last City: " << dataVector[i].previousCity << endl;
}

}
void DDFS::print() {
	for (int i = 0; i < departureNodes.size(); i++) {
		departureNodes[i].print();
	}
}
