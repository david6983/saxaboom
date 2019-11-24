#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Saxaboom2AudioProcessorEditor  : public AudioProcessorEditor,
									   public Slider::Listener,
									   public Button::Listener
{
public:
    Saxaboom2AudioProcessorEditor (Saxaboom2AudioProcessor&);
    ~Saxaboom2AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void sliderValueChanged(Slider* sliderThatWasMoved) override;
	void buttonClicked(Button* buttonThatWasClicked) override;

	// Binary resources:
	static const char* background_png;
	static const int background_pngSize;
	static const char* button_png;
	static const int button_pngSize;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Saxaboom2AudioProcessor& processor;
    
	std::unique_ptr<Slider> slider;
	std::unique_ptr<TextButton> textButton;
	std::unique_ptr<ImageButton> imageButton;
	std::unique_ptr<ImageButton> imageButton2;
	std::unique_ptr<ImageButton> imageButton3;
	std::unique_ptr<ImageButton> imageButton4;
	std::unique_ptr<ImageButton> imageButton5;
	std::unique_ptr<ImageButton> imageButton6;
	std::unique_ptr<ImageButton> imageButton7;
	Image cachedImage_background_png_1;
	
	std::unique_ptr<HyperlinkButton> author_name;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Saxaboom2AudioProcessorEditor)
};
