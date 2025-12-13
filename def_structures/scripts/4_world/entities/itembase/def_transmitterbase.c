modded class TransmitterBase //extends ItemTransmitter
{
    bool debug = false;

    ref Timer checkForRadiowaveTransmittersTimer;
    static ref array<vector> s_ActiveDynamicRadiowaveTransmitters = new array<vector>();  //all radios should have same knowledge
    string SOUNDSET__RADIOWAVE_TRANSMITTER_DETECTED = "DEF_RadioNoise_SoundSet_";
	protected EffectSound m_DetectionSound;

    void TransmitterBase()
    {
        checkForRadiowaveTransmittersTimer = new Timer();
    }
    
	override void OnWorkStart()
	{
		super.OnWorkStart();
        DEF_DetectDynamicRadiowaveTransmitter_PlaySoundNoise_Start();

        if (debug)
        {
            Print("[DEF DEBUG] : LISTING ALL RADIOWAVE_TRANSMITTERS");
            foreach (vector radiowaveTransmitterPos : TransmitterBase.s_ActiveDynamicRadiowaveTransmitters)
            {
                Print(radiowaveTransmitterPos);
            }
        }
        
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
        DEF_DetectDynamicRadiowaveTransmitter_PlaySoundNoise_Stop();
	}
    
	protected void DEF_DetectDynamicRadiowaveTransmitter_PlaySoundNoise_Start()
    {
        int checkForRadiowaveTransmittersTimer_secondsInterval = GetGame().ServerConfigGetInt("checkForRadiowaveTransmittersTimer_secondsInterval");
        if (checkForRadiowaveTransmittersTimer_secondsInterval == 0)
        {
           checkForRadiowaveTransmittersTimer_secondsInterval = 90;
        }

        checkForRadiowaveTransmittersTimer.Run(checkForRadiowaveTransmittersTimer_secondsInterval, this, "DEF_CheckForRadiowaveTransmitters", NULL, true);
        
        if (debug)
        {
            Print("[DEF DEBUG] - checkForRadiowaveTransmittersTimer_secondsInterval = " + checkForRadiowaveTransmittersTimer_secondsInterval)
        }
    }

	protected void DEF_DetectDynamicRadiowaveTransmitter_PlaySoundNoise_Stop()
	{
        StopSoundSet( m_DetectionSound );
        checkForRadiowaveTransmittersTimer.Stop();
	}

    static bool DEF_IsVectorEqual(vector a, vector b, float tolerance = 5)
    {
        return vector.Distance(a, b) <= tolerance;
    }

    static bool DEF_IsVectorZero(vector position)
    {
        if (position == Vector(0.000000, 0.000000, 0.000000))
        {
            return true;
        }
        else if (vector.Distance(position, vector.Zero) < 0.1)
        {
            return true;
        }

        return false;
    }

    static void DEF_AddTransmitterToList(vector position)
    {
        if(!DEF_IsVectorZero(position))
        {
            for (int i = 0; i < s_ActiveDynamicRadiowaveTransmitters.Count(); i++)
            {
                if (s_ActiveDynamicRadiowaveTransmitters[i] == position)    //uniqueness check
                    return;
            }

            TransmitterBase.s_ActiveDynamicRadiowaveTransmitters.Insert(position);
            if (debug)
            {
                Print("[DEF DEBUG] - Added radiowaveTransmitter to list at: " + position);
            }
        }
    }

    static void DEF_RemoveTransmitterFromList(vector position)
    {
        if(!DEF_IsVectorZero(position))
        {
            int index = -1;
            for (int i = 0; i < s_ActiveDynamicRadiowaveTransmitters.Count(); i++)
            {
                if (DEF_IsVectorEqual(s_ActiveDynamicRadiowaveTransmitters[i], position))
                {
                    index = i;
                    break;
                }
            }

            if (index != -1)
            {
                s_ActiveDynamicRadiowaveTransmitters.Remove(index);

                if (debug)
                {
                    Print("[DEF DEBUG] - Removed radiowaveTransmitter at: " + position);
                }
            }
            else
            {
                if (debug)
                {
                    Print("[DEF DEBUG] - No radiowaveTransmitter found to remove at: " + position);
                }
            }
        }
    }

    protected void DEF_CheckForRadiowaveTransmitters()
    {
        ref array<int> distanceThresholds = {
            10, 
            25, 
            50, 
            100, 
            200, 
            300, 
            400, 
            500, 
            600, 
            700, 
            800, 
            900, 
            1000, 
            1200, 
            2000
        };

        float closestDistance = 999999; //Used to not play multiple sound for different radiowaveTransmitters in range
        foreach (vector radiowaveTransmitterPos : TransmitterBase.s_ActiveDynamicRadiowaveTransmitters)
        {
            float distance = vector.Distance(GetPosition(), radiowaveTransmitterPos);
            if (distance < closestDistance)
                closestDistance = distance;
        }

        foreach (int threshold : distanceThresholds)
        {
            if (closestDistance < threshold)
            {
                string distanceBasedSound = SOUNDSET__RADIOWAVE_TRANSMITTER_DETECTED + threshold;
                PlaySoundSet(m_DetectionSound, distanceBasedSound, 1.0, 1.0);

                if (debug)
                {
                    Print("PLAYING: " + distanceBasedSound + " (closest radiowaveTransmitter)");
                }

                break;
            }
        }
    }
}