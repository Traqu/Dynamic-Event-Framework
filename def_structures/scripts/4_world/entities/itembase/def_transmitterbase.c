modded class TransmitterBase //extends ItemTransmitter
{
    ref Timer checkForTransmittersTimer;
    static ref array<vector> s_ActiveDynamicTransmitters = new array<vector>();  //all radios should have same knowledge
    string SOUND_TRANSMITTER_DETECTED = "DEF_RadioNoise_SoundSet_";
	protected EffectSound m_DetectionSound;

    void TransmitterBase()
    {
        checkForTransmittersTimer = new Timer();
    }
    
	override void OnWorkStart()
	{
		super.OnWorkStart();
        DEF_DetectDynamicCamp_PlaySoundNoise_Start();

        //Print("[DEF DEBUG] : LISTING ALL TRANSMITTERS");
        // foreach (vector campPos : TransmitterBase.s_ActiveDynamicTransmitters)
        // {
        //     Print(campPos);
        // }
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
        DEF_DetectDynamicCamp_PlaySoundNoise_Stop();
	}
    
	protected void DEF_DetectDynamicCamp_PlaySoundNoise_Start()
    {
        int checkForTransmittersTimer_secondsInterval = GetGame().ServerConfigGetInt("checkForTransmittersTimer_secondsInterval");
        if (checkForTransmittersTimer_secondsInterval < 10)
        {
           checkForTransmittersTimer_secondsInterval = 90;
        }
        checkForTransmittersTimer.Run(checkForTransmittersTimer_secondsInterval, this, "DEF_CheckForTransmitters", NULL, true);
        //Print("[DEF DEBUG] - checkForTransmittersTimer_secondsInterval = " + checkForTransmittersTimer_secondsInterval);
    }

	protected void DEF_DetectDynamicCamp_PlaySoundNoise_Stop()
	{
        StopSoundSet( m_DetectionSound );
        checkForTransmittersTimer.Stop();
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
            for (int i = 0; i < s_ActiveDynamicTransmitters.Count(); i++)
            {
                if (s_ActiveDynamicTransmitters[i] == position)    //uniqueness check
                    return;
            }

            TransmitterBase.s_ActiveDynamicTransmitters.Insert(position);
            //Print("[DEF DEBUG] - Added camp to list at: " + position);
        }
    }

    static void DEF_RemoveTransmitterFromList(vector position)
    {
        if(!DEF_IsVectorZero(position))
        {
            int index = -1;
            for (int i = 0; i < s_ActiveDynamicTransmitters.Count(); i++)
            {
                if (DEF_IsVectorEqual(s_ActiveDynamicTransmitters[i], position))
                {
                    index = i;
                    break;
                }
            }

            if (index != -1)
            {
                s_ActiveDynamicTransmitters.Remove(index);
                //Print("[DEF DEBUG] - Removed camp at: " + position);
            }
            // else
            // {
            //     Print("[DEF DEBUG] - No camp found to remove at: " + position);
            // }
        }
    }

    protected void DEF_CheckForTransmitters()
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

        float closestDistance = 999999; //Used to not play multiple sound for different transmitters in range
        foreach (vector campPos : TransmitterBase.s_ActiveDynamicTransmitters)
        {
            float distance = vector.Distance(GetPosition(), campPos);
            if (distance < closestDistance)
                closestDistance = distance;
        }

        foreach (int threshold : distanceThresholds)
        {
            if (closestDistance < threshold)
            {
                string distanceBasedSound = SOUND_TRANSMITTER_DETECTED + threshold;
                PlaySoundSet(m_DetectionSound, distanceBasedSound, 1.0, 1.0);
                //Print("PLAYING: " + distanceBasedSound + " (closest camp)");
                break;
            }
        }
    }
}