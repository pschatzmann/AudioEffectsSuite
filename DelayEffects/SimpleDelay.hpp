//
//  SimpleDelay.hpp
//  AudioEffectsSuiteDevelopment
//
//  Created by admin on 18/12/2017.
//  Copyright © 2017 AudioEffectsSuiteTeam. All rights reserved.
//

#ifndef SimpleDelay_hpp
#define SimpleDelay_hpp

#include <iostream>
#include <cmath>
#include "../BaseClasses/DelayEffectBase.cpp"

class SimpleDelay;
//==============================================================================
/**
	Delay Effect Class for applying an delay effect onto an audio stream,
	sample by sample
	
	Constructor requires internal delay in samples
	
	@see process
 */
class SimpleDelay : public DelayEffectBase
{
public: // Methods
	//==============================================================================
	/** Constructor: DigitalEffect Base Must Be initialised
	 
		@param delayInSamples Set the amount of delay in samples
		
		@see DelayEffectBase constructor
	 */
	SimpleDelay(int delayInSamples) : DelayEffectBase(44100){delayTimeSamples=delayInSamples;};
	
	/** Destructor. */
	~SimpleDelay(){};
	
	/** setDelayGain: sets the delay gain to a value between 1 and -1
	 
		@param gain		required delay gain. Values beyond 1 and -1
	 are capped to the maximum to avoid idiocy.
	 Negative velus invoke a phase inversion.
	 
		@see setFeedbackGain
	 */
	void setDelayGain(double gain);
	
	/** setDelayGain: sets the feedback gain to a value between 1 and -1
	 
		@param gain		required delay gain. Values beyond 1 and -1
	 are capped to the maximum to avoid idiocy.
	 Negative velus invoke a phase inversion.
	 
		@see setDelayGain
	 */
	void setFeedbackGain(double gain);
	
	//==============================================================================
	/**Delay sample by 1 seconds and*/
	double process(double inputSample) override;
private: //Methods
	/** capGain: caps gain to a range of 1 and -1;
	*	@param gain address of gain value
	*/
	void capGain(double& gain);

private: //member vairables
	/***/
	double delayGain=.707, feedbackGain=0.;
};

#endif /* SimpleDelay_hpp */
