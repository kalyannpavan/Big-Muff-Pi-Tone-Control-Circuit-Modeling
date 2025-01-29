// ==================================| Third Party Node Template |==================================

#pragma once
#include <JuceHeader.h>

namespace project
{
using namespace juce;
using namespace hise;
using namespace scriptnode;

// ==========================| The node class with all required callbacks |==========================

template <int NV> struct BigMuffTone: public data::base
{
	// Metadata Definitions ------------------------------------------------------------------------
	
	SNEX_NODE(BigMuffTone);

	double Fs = 0;
	double Ts = 0;


	double C9 = 4e-9;         
	double CR9 = 0;    
	double CX9 = 0;           

	double C8 = 10e-9;         
	double CR8 = 0;    
	double CX8 = 0;              

	double R8 = 39e3;      
	double R5 = 22e3;            

	double Tone = 100e3;      
	double ToneAlpha = 0.5;     
	double ToneA = 0; 
	double ToneB = 0;


	double a = 0;
	double b = 0;


	double Vin = 0;
	double Vout = 0;

	double Va = 0;
	double Vb = 0;
	
	struct MetadataClass
	{
		SN_NODE_ID("BigMuffTone");
	};
	
	// set to true if you want this node to have a modulation dragger
	static constexpr bool isModNode() { return false; };
	static constexpr bool isPolyphonic() { return NV > 1; };
	// set to true if your node produces a tail
	static constexpr bool hasTail() { return false; };
	// set to true if your doesn't generate sound from silence and can be suspended when the input signal is silent
	static constexpr bool isSuspendedOnSilence() { return false; };
	// Undefine this method if you want a dynamic channel count
	static constexpr int getFixChannelAmount() { return 2; };
	
	// Define the amount and types of external data slots you want to use
	static constexpr int NumTables = 0;
	static constexpr int NumSliderPacks = 0;
	static constexpr int NumAudioFiles = 0;
	static constexpr int NumFilters = 0;
	static constexpr int NumDisplayBuffers = 0;
	
	// Scriptnode Callbacks ------------------------------------------------------------------------
	
	void prepare(PrepareSpecs specs)
	{
		Fs = specs.sampleRate;
		Ts = 1.0/Fs;

		CR9 = Ts/(2.0*C9);
		CR8 = Ts/(2.0*C8); 
	}
	
	void reset()
	{
		
	}
	
	void handleHiseEvent(HiseEvent& e)
	{
		
	}

		template <typename T> void process(T& data)
	{
		
		static constexpr int NumChannels = getFixChannelAmount();
		// Cast the dynamic channel data to a fixed channel amount
		auto& fixData = data.template as<ProcessData<NumChannels>>();
		
		// Create a FrameProcessor object
		auto fd = fixData.toFrameData();
		
		while(fd.next())
		{
			Vin = fd[0];


        	Vout = ((ToneA / a) * (Vin / R8 + CX8) + (ToneB / b) * (-CX9 + Vin / CR9)) / (ToneA + ToneB - (ToneA / (a * ToneB)) - (ToneB / (b * ToneA)));

			fd[0] = Vout;

			// Forward to frame processing
			processFrame(fd.toSpan());

			
			Va = ((Vin/R8) + (Vout/ToneB) + CX8) / a;
        	Vb = (((Vout/ToneA) - CX9) + (Vin/CR9)) / b;

			CX8 = (2/CR8) * Va - CX8;
        	CX9 = (2/CR9) * (Vin - Vb) - CX9;


		}
		
	}

	
	template <typename T> void processFrame(T& data)
	{
		
	}
	
	int handleModulation(double& value)
	{
		
		return 0;
		
	}
	
	void setExternalData(const ExternalData& data, int index)
	{
		
	}
	// Parameter Functions -------------------------------------------------------------------------
	
	template <int P> void setParameter(double v)
	{
		if (P == 0)
		{
			ToneAlpha=(double)v;
			// This will be executed for MyParameter (see below)
			jassertfalse;
		}
		ToneA = (1-ToneAlpha) * Tone;
        ToneB = ToneAlpha * Tone;

		a = ((1/CR8) + (1/ToneB) + (1/R8));
        b = ((1/R5) + (1/ToneA) + (1/CR9));

		
	}
	
	void createParameters(ParameterDataList& data)
	{
		{
			// Create a parameter like this
			parameter::data p("Tone", { 0.0, 1.0 });
			// The template parameter (<0>) will be forwarded to setParameter<P>()
			registerCallback<0>(p);
			p.setDefaultValue(0.5);
			data.add(std::move(p));
		}
	}
};
}


