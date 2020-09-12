#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <thread>
#include <iostream>
using namespace std;
int max_number =  600;
const int s = 600;
int a[s];

class Window : public olc::PixelGameEngine
{
	int width = 2;
public:

	Window()
	{

	}

public:
	bool OnUserCreate() override
	{
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::WHITE);
		
		for (int i = 0; i < s; i++)
		{
			DrawRect(i*width, ScreenHeight()-a[i], width, a[i], olc::BACK);
			
		}
		return true;
	}

};

void buble_sort()
{
	bool sorted = true;
	do
	{
		std::this_thread::sleep_for(1ms);
		sorted = true;
		for (int i = 0; i < s; i++)
		{
			
			if (i< s - 1 && a[i] > a[i + 1])
			{
				
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				sorted = false;
				break;
			}
		}
	} while (!sorted);

};

void insertion_sort()
{
	for (int j = 1; j < s; j++)
	{
		std::this_thread::sleep_for(10ms);
		int key = a[j];
		int i = j - 1;
		while (i>=0 && a[i]> key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

int main()
{
	

	Window w;
	std::thread sort_thread(insertion_sort);

	w.Construct(s*2, max_number, 1, 1);
	for (int i = 0; i < s; i++)
	{
		a[i] = rand() % max_number;
	}


	w.Start();
	
	sort_thread.join();

	cout << "End of program " << endl;


	return 0;
}