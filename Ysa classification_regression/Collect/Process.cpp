#include "pch.h"
#include <cmath>

float* Add_Data(float* sample, int Size, float* x, int Dim) {
	float* temp = new float[Size * Dim];
	for (int i = 0; i < (Size - 1) * Dim; i++)
		temp[i] = sample[i];
	for (int i = 0; i < Dim; i++)
		temp[(Size - 1) * Dim + i] = x[i];
	//Deallocate memory
	delete[] sample;
	return temp;
}//Add_data
float* Add_Labels(float* Labels, int Size, int label) {
	float* temp = new float[Size];
	for (int i = 0; i < Size - 1; i++)
		temp[i] = Labels[i];
	temp[Size - 1] = float(label);
	//Deallocate memory
	delete[] Labels;
	return temp;
}
float* init_array_random(int len) {
	float* arr = new float[len];
	for (int i = 0; i < len; i++)
		arr[i] = ((float)rand() / RAND_MAX) - 0.5f;
	return arr;
}
void Z_Score_Parameters(float* x, int Size, int dim, float* mean, float* std) {

	float* Total = new float[dim];

	int i, j;
	for (i = 0; i < dim; i++) {
		mean[i] = std[i] = Total[i] = 0.0;
	}
	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			Total[j] += x[i * dim + j];
	for (i = 0; i < dim; i++)
		mean[i] = Total[i] / float(Size);

	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			std[j] += ((x[i * dim + j] - mean[j]) * (x[i * dim + j] - mean[j]));

	for (j = 0; j < dim; j++)
		std[j] = sqrt(std[j] / float(Size));

	delete[] Total;

}//Z_Score_Parameters
int Classification(float* sample, float* Weights, float* bias, int layer, int* neuron_count, int inputDim)
{
	int* neuronOffset = new int[layer + 1];
	int* weightOffset = new int[layer + 1];

	neuronOffset[0] = 0;
	weightOffset[0] = 0;

	for (int i = 0; i < layer; ++i)
	{
		int current_layer_weights = 0;

		if (i == 0)
			current_layer_weights = inputDim * neuron_count[i];
		else
			current_layer_weights = neuron_count[i - 1] * neuron_count[i];

		weightOffset[i + 1] = weightOffset[i] + current_layer_weights; // weight toplamý
		neuronOffset[i + 1] = neuronOffset[i] + neuron_count[i];       // nöron toplamý
	}

	int totalNeuronCount = neuronOffset[layer];
	float* f_net = new float[totalNeuronCount];

	// --- Forward geçiþ ---
	for (int l = 0; l < layer; ++l)
	{
		int neuronBase = neuronOffset[l];
		int weightBase = weightOffset[l];

		if (l == 0)
		{
			// Ýlk katman: giriþ -> ilk gizli/çýktý katmaný
			for (int k = 0; k < neuron_count[l]; ++k)
			{
				float sum = 0.0f;

				for (int i = 0; i < inputDim; ++i)
				{
					int wIndex = weightBase + k * inputDim + i;
					sum += Weights[wIndex] * sample[i];
				}

				sum += bias[neuronBase + k];

				f_net[neuronBase + k] = (2.0f / (1.0f + System::Math::Exp(-sum))) - 1.0f;
			}
		}
		else
		{
			// Ara katmanlar / son katman
			int prevNeuronBase = neuronOffset[l - 1];
			int prevCount = neuron_count[l - 1];

			for (int k = 0; k < neuron_count[l]; ++k)
			{
				float sum = 0.0f;

				for (int i = 0; i < prevCount; ++i)
				{
					int wIndex = weightBase + k * prevCount + i;
					sum += Weights[wIndex] * f_net[prevNeuronBase + i];
				}

				sum += bias[neuronBase + k];

				f_net[neuronBase + k] = (2.0f / (1.0f + System::Math::Exp(-sum))) - 1.0f;
			}
		}
	}

	// çýktý nöronlarý arasýndan en büyük skorun indexini bul
	int outputBase = neuronOffset[layer - 1];
	int index_Max = 0;
	float max_score = -9999.0f;

	for (int i = 0; i < neuron_count[layer - 1]; ++i)
	{
		float val = f_net[outputBase + i];
		if (val > max_score)
		{
			max_score = val;
			index_Max = i;
		}
	}

	delete[] f_net;
	delete[] neuronOffset;
	delete[] weightOffset;

	return index_Max;
}

float Regression(float* sample, float* Weights, float* bias, int layer, int* neuron_count, int inputDim)
{
	int* neuronOffset = new int[layer + 1];
	int* weightOffset = new int[layer + 1];

	neuronOffset[0] = 0;
	weightOffset[0] = 0;

	for (int i = 0; i < layer; ++i)
	{
		int current_layer_weights = 0;

		if (i == 0)
			current_layer_weights = inputDim * neuron_count[i];
		else
			current_layer_weights = neuron_count[i - 1] * neuron_count[i];

		weightOffset[i + 1] = weightOffset[i] + current_layer_weights;
		neuronOffset[i + 1] = neuronOffset[i] + neuron_count[i];
	}

	int totalNeuronCount = neuronOffset[layer];
	float* f_net = new float[totalNeuronCount];

	for (int i = 0; i < totalNeuronCount; ++i)
		f_net[i] = 0.0f;

	// Forward geçiþ
	for (int l = 0; l < layer; ++l)
	{
		int neuronBase = neuronOffset[l];
		int weightBase = weightOffset[l];

		if (l == 0)
		{
			// Ýlk katman: giriþ -> ilk gizli/çýktý katmaný
			for (int k = 0; k < neuron_count[l]; ++k)
			{
				float sum = 0.0f;

				for (int i = 0; i < inputDim; ++i)
				{
					int wIndex = weightBase + k * inputDim + i;
					sum += Weights[wIndex] * sample[i];
				}

				sum += bias[neuronBase + k];

				if (l == layer - 1) // tek katmanlý regresyon
					f_net[neuronBase + k] = sum; // son katman: lineer
				else
					f_net[neuronBase + k] = (2.0f / (1.0f + System::Math::Exp(-sum))) - 1.0f;
			}
		}
		else
		{
			int prevNeuronBase = neuronOffset[l - 1];
			int prevCount = neuron_count[l - 1];

			for (int k = 0; k < neuron_count[l]; ++k)
			{
				float sum = 0.0f;

				for (int i = 0; i < prevCount; ++i)
				{
					int wIndex = weightBase + k * prevCount + i;
					sum += Weights[wIndex] * f_net[prevNeuronBase + i];
				}

				sum += bias[neuronBase + k];

				if (l == layer - 1)
					f_net[neuronBase + k] = sum; // son katman lineer
				else
					f_net[neuronBase + k] = (2.0f / (1.0f + System::Math::Exp(-sum))) - 1.0f;
			}
		}
	}

	float output = f_net[neuronOffset[layer - 1]];

	delete[] f_net;
	delete[] neuronOffset;
	delete[] weightOffset;

	return output;
}
