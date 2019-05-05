////Train and recogize perceptron
////Programmmer: supakitnootyaskool@gmail.com
////Create date: 30 Jan 2019
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//#include <conio.h>
//
//const int maxInput = 9;
//
//int patternTrain[3][maxInput] =
//{
//	{	0,1,0,
//		0,1,0,
//		0,1,0},
//
//	 {	1,1,1,
//		0,1,0,
//		1,1,1 },
//
//	{	0,0,0,
//		1,1,1,
//		0,0,0 },
//};
//
//int patternTest[3][maxInput] =
//{
//	{ 0,1,0,
//	  1,1,1,
//	  0,1,0 },
//
//	{ 1,1,1,
//	1,1,1,
//	1,1,1 },
//
//	{ 1,1,1,
//	1,1,1,
//	1,1,1 },
//};
//
//double uniformRandom0_1()
//{
//	double r;
//	r = rand() / (double) RAND_MAX;
//	return r;
//}
//double uniformRandom1_1()
//{
//	double r;
//	r = rand() / (double)RAND_MAX;
//	return r;
//}
//
//double sigmoid0_1(double x)
//{	//"S" curve function from 0 to 1 
//	double s;
//	s = 1 / (1 + exp(-x));
//	return s;
//}
//
//double sigmoid1_1(double x)
//{	//"S" curve function from 0 to 1 
//	double s;
//	s = 1 / (1 + exp(-x));
//	return s;
//}
//
//double unitstep(double t0, double t1)
//{	//t0 is a data in the previous
//	//t1 is a data in the current
//	if (t1 < t0)
//		return 0;
//	if (t1 >= t0)
//		return 1;
//}
//
//class Perceptron
//{
//	/* We can draw picture of the perceptron as below
//		i0  --> w0 --> 
//		i1  --> w1 -->
//		..					Net = Sum in*wn	   --> sigmoidFunction (0/1) --> O
//		in  --> wn -->			  from 0 to N
//	This class represented a neuron. so, the limitation parameter in this class defined a maximum input at 100, weight at 100 and a output.
//	*/
//	
//private:
//	double i[100];
//	double w[100];
//	double net;
//	double out;
//	double desiredout;
//	int maxN;
//
//
//public:
//
//	void setN(int v)
//	{
//		maxN = v;
//	}
//	
//	void setInput(int *pattern)
//	{
//		for (int p = 0; p < maxN; p++)
//		{
//			i[p] = pattern[p];
//		}
//	}
//
//	void generateWeight(void)
//	{
//		for (int n = 0; n < maxN; n++)
//			w[n] = uniformRandom0_1();
//	}
//	double calculateNet()
//	{
//		double s = 0;
//		for (int n = 0; n < maxN; n++)
//		{
//			s += i[n] * w[n];
//		}
//		net = s;
//		return s;
//	}
//	double calculateOutput()
//	{
//		//activation function
//		if (net >= 0)
//			out = 1;
//		else
//			out = 0;
//		return out;
//	}
//	void show(void)
//	{
//		printf("\n     Net(%f) -->  Out(%f)", net, out);
//	}
//	
//	void adjustWeight(void)
//	{
//		//Adjust weigth is the learning process of the perceptron.
//		//Equation is    wj(t+1) = wj(t) + l(d-y)x
//		//the meansing is  a new weight come =   the old weigth + learnning rate(the desired output - the current output) * input
//		//the importance is "(the desired output - the current output)" should be -1 to 1. 
//		double wbar[maxInput];
//		double lr = 0.5;
//		for (int p = 0; p < maxN; p++)
//		{
//			wbar[p] = w[p] + lr * (0 - out) * i[p];
//			printf("\n		oldW(%f) -> newW(%f)",w[p], wbar[p]);
//			w[p] = wbar[p];
//		}
//		lr = lr;
//	}
//	void loopAdjustWeight(void)
//	{
//		int k = 0;
//		do{
//			adjustWeight();
//			calculateNet();
//			calculateOutput();
//			show();
//			k++;
//		} while (out > 0 && k < 100);
//			printf("\n stop at %d", k);
//	}
//
//
//};
//
//
//int main(void)
//{
//	srand(time(NULL));
//
//	Perceptron	np[3];
//	np[0].setN(9);
//	np[1].setN(9);
//	np[2].setN(9); 
//
//
//	np[0].setInput(&patternTrain[0][0]);
//	np[1].setInput(&patternTrain[1][0]);
//	np[2].setInput(&patternTrain[2][0]);
//
//	np[0].generateWeight();
//	np[1].generateWeight();
//	np[2].generateWeight();
//
//	np[0].calculateNet();
//	np[1].calculateNet();
//	np[2].calculateNet();
//
//	np[0].calculateOutput();
//	np[1].calculateOutput();
//	np[2].calculateOutput();
//
//	np[0].show();
//	np[1].show();
//	np[2].show();
//
//	np[0].loopAdjustWeight();
//	np[1].loopAdjustWeight();
//	np[2].loopAdjustWeight();
//
//	np[0].show();
//	np[1].show();
//	np[2].show();
//
//	printf("\n----Testing--");
//
//	printf("\n Pattern 2 tests on the model of pattern1");
//	np[0].setInput(&patternTrain[1][0]);
//	np[0].calculateNet();
//	np[0].calculateOutput();
//	np[0].show();
//
//	printf("\n Pattern 3 tests on the model of pattern1");
//	np[0].setInput(&patternTrain[2][0]);
//	np[0].calculateNet();
//	np[0].calculateOutput();
//	np[0].show();
//
//	printf("\n Test pattern 1 tests on the model of pattern1");
//	np[0].setInput(&patternTest[0][0]);
//	np[0].calculateNet();
//	np[0].calculateOutput();
//	np[0].show();
//
//	getchar();
//	return 0;
//}