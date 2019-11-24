/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Saxaboom2AudioProcessor::Saxaboom2AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{

	formatManager.registerBasicFormats();

	
	synth = new Synthesiser();

	synth->addVoice(new SamplerVoice());
	
	auto dir = File::getSpecialLocation(File::userDocumentsDirectory).getChildFile("Saxaboom").getChildFile("Samples");

	loadNewSampleAtChannel(dir.getChildFile("sbLoop.wav"), 60);
	loadNewSampleAtChannel(dir.getChildFile("sbLoop1.wav"), 61);
	loadNewSampleAtChannel(dir.getChildFile("sbLoop2.wav"), 62);
	loadNewSampleAtChannel(dir.getChildFile("sbLoop3.wav"), 63);
	loadNewSampleAtChannel(dir.getChildFile("sbLoop4.wav"), 64);
	loadNewSampleAtChannel(dir.getChildFile("sbLoop5.wav"), 65);
	loadNewSampleAtChannel(dir.getChildFile("sbLoop6.wav"), 66);
	loadNewSampleAtChannel(dir.getChildFile("sbLoop8.wav"), 67);
	
	triggerNote = 0;
	addParameter(mainVelocity = new AudioParameterInt("mainVelocity", "MainVelocity", 0, 127, 127));
}

Saxaboom2AudioProcessor::~Saxaboom2AudioProcessor()
{
	delete synth; synth = nullptr;
}

//==============================================================================
const String Saxaboom2AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Saxaboom2AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Saxaboom2AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Saxaboom2AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Saxaboom2AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Saxaboom2AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Saxaboom2AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Saxaboom2AudioProcessor::setCurrentProgram (int index)
{
}

const String Saxaboom2AudioProcessor::getProgramName (int index)
{
    return {};
}

void Saxaboom2AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Saxaboom2AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    ignoreUnused(samplesPerBlock);

	synth->setCurrentPlaybackSampleRate(sampleRate);
}

void Saxaboom2AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Saxaboom2AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Saxaboom2AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	//filter out the unnecessary audio bus buffers and filter out the midi messages that
	//do not correspond to the midi channel of the synthesiser by calling a private helper function 
	auto midiChannelBuffer = filterMidiMessagesForChannel(midiMessages, 1);
	
	//handle midi events from UI buttons
	switch (triggerNote) {
	case 1:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 60, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	case 2:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 61, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	case 3:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 62, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	case 4:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 63, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	case 5:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 64, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	case 6:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 65, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	case 7:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 66, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	case 8:
		midiChannelBuffer.addEvent(MidiMessage::noteOn(1, 67, (uint8)(*mainVelocity)), 0);
		triggerNote = 0;
		break;
	}
	auto audioBusBuffer = getBusBuffer(buffer, false, 0);

	//We can then call the renderNextBlock() function directly on the corresponding Synthesiser object to generate the sound
	//by supplying the correct audio bus buffer and midi channel buffer
	synth->renderNextBlock(audioBusBuffer, midiChannelBuffer, 0, audioBusBuffer.getNumSamples());
}

//==============================================================================
bool Saxaboom2AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Saxaboom2AudioProcessor::createEditor()
{
    return new Saxaboom2AudioProcessorEditor (*this);
}

//==============================================================================
void Saxaboom2AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    //std::unique_ptr<XmlElement> xml(new XmlElement("Parameter"));
	//xml->setAttribute("mainVelocity", *mainVelocity);
	//copyXmlToBinary(*xml, destData);
}

void Saxaboom2AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	if (xmlState.get() != nullptr) {
		if (xmlState->hasTagName("ParamTutorial")) {
			*mainVelocity = xmlState->getIntAttribute("mainVelocity", 127);
		}
	}
}

MidiBuffer Saxaboom2AudioProcessor::filterMidiMessagesForChannel(const MidiBuffer & input, int channel)
{
	MidiMessage msg;
	int samplePosition;
	MidiBuffer output;

	//For every midi channel buffer, we check whether the midi message channel matches the midi channel of the ouput bus we are looking for and
	//if so we add the MidiMessage to a newly-created MidiBuffer

	for (MidiBuffer::Iterator it(input); it.getNextEvent(msg, samplePosition);) 
		if (msg.getChannel() == channel) output.addEvent(msg, samplePosition);

	//When we have iterated over all midi messages in all midi channels, we return with a buffer containing only 
	//the midi messages of the selectedchannel
	return output;
}

void Saxaboom2AudioProcessor::loadNewSampleAtChannel(const File& sampleFile, int midiNote)
{
	//Create a MemoryInputStream from the sample binary data
	auto* soundBuffer = sampleFile.createInputStream();
	//Convert the stream to read the files as a "wav" file
	std::unique_ptr<AudioFormatReader> formatReader(formatManager.findFormatForFileExtension("wav")->createReaderFor(soundBuffer, true));

	BigInteger midiNotes;
	//the sound is asigned on one midi key only
	midiNotes.setRange(midiNote, midiNote + 1, true);
	//so the next midi keys msut be disabled 
	midiNotes.setRange(midiNote + 1, 128, false);

	//Declare a SamplerSound object with the previously created stream reader and constrain the range of midi notes using BigInteger
	SynthesiserSound::Ptr newSound = new SamplerSound("Voice", *formatReader, midiNotes, midiNote, 0.0, 10.0, 10.0);

	//Add the new sound to the synth
	synth->addSound(newSound);
}
//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Saxaboom2AudioProcessor();
}
