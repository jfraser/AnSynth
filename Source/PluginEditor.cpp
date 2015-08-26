/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AnSynthAudioProcessorEditor::AnSynthAudioProcessorEditor (AnSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 300);
    addAndMakeVisible(freqSlider);
    freqSlider.setRange(50.0, 5000.0);
    freqSlider.setTextValueSuffix(" Hz");
    freqSlider.setTextBoxStyle(Slider::TextBoxLeft, false, 160, freqSlider.getTextBoxHeight());
    freqSlider.setSkewFactorFromMidPoint (500);
    freqSlider.addListener(this);
    
    addAndMakeVisible(freqLabel);
    freqLabel.setText("Frequency", dontSendNotification);
    freqLabel.attachToComponent(&freqSlider, true);
}

AnSynthAudioProcessorEditor::~AnSynthAudioProcessorEditor()
{
}

//==============================================================================
void AnSynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
}

void AnSynthAudioProcessorEditor::resized()
{
    const int sliderLeft = 120;
    freqSlider.setBounds(sliderLeft, 20, getWidth() - sliderLeft - 10, 20);
}

void AnSynthAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    processor.freq = freqSlider.getValue();
}
