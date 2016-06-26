#pragma once
//#include "Connection.h"
#include "Neuron.h"
#include <vector>
#include "LinkedList.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class NeuralNetwork {
public:
	vector<vector<Neuron>> neuralNetwork;
	vector <Connection*> connections;
	vector<double> currentInput;
	double networkError = 0;
	double learningRate = .5;
	double momentum = .45;
	LinkedList<vector<double>, vector<double>> trainingValues;

	Neuron * findNeuron(double id);

	void optimize(); 

	void reset();

	void process();
	void process(vector<double> input);

	vector<Connection*> getConnections(Neuron neuron);
	vector<Connection*> getConnectionsFrom(Neuron neuron);

	void fix(vector<double> inputs, vector<double> desired);

	void fix(vector<double> desired);

	double calcNetInput(Neuron input);

	void adjustConstants(double currentError, double lastError);

	void  initializeNN(int input, vector<int> hidden, int output);

	void addAllConnections();
	LinkedList<vector<double>, vector<double>> limit(LinkedList<vector<double>, vector<double>> input, int amount);
	double calcDifference(vector<double> one, vector<double> two);
	double calcError(vector<double> desired);
	LinkedList<vector<double>, vector<double>> staggerDesired(LinkedList<vector<double>, vector<double>> input);
	LinkedList<vector<double>, vector<double>> tweakDesired(LinkedList<vector<double>, vector<double>> input);
	double train(LinkedList<vector<double>, vector<double>> inputs);
	double train();

	void autoPrune();
	void autoPrune(LinkedList<vector<double>, vector<double>> input, int layerNumber);
	double calcSigmoid(double netInput);
	double calcTanh(double netInput);
	double tanhDerivative(double x);
	double sech(double x);
};