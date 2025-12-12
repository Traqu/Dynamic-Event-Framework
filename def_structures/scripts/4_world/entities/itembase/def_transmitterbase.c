modded class TransmitterBase //extends ItemTransmitter
{
    bool debug = false;

    ref Timer checkForCampsTimer;
    static ref array<vector> s_ActiveDynamicCamps = new array<vector>();  //all radios should have same knowledge
    string SOUND_CAMP_DETECTED = "DEF_RadioNoise_SoundSet_";
	protected EffectSound m_DetectionSound;

    void TransmitterBase()
    {
        checkForCampsTimer = new Timer();
    }
    
	override void OnWorkStart()
	{
		super.OnWorkStart();
        DEF_DetectDynamicCamp_PlaySoundNoise_Start();

        if (debug)
        {
            Print("[DEF DEBUG] : LISTING ALL CAMPS");
            foreach (vector campPos : TransmitterBase.s_ActiveDynamicCamps)
            {
                Print(campPos);
            }
        }
        
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
        DEF_DetectDynamicCamp_PlaySoundNoise_Stop();
	}
    
	protected void DEF_DetectDynamicCamp_PlaySoundNoise_Start()
    {
        int checkForCampsTimer_secondsInterval = GetGame().ServerConfigGetInt("checkForCampsTimer_secondsInterval");
        if (checkForCampsTimer_secondsInterval == 0)
        {
           checkForCampsTimer_secondsInterval = 90;
        }
        checkForCampsTimer.Run(checkForCampsTimer_secondsInterval, this, "DEF_CheckForCamps", NULL, true);
        
        if (debug)
        {
            Print("[DEF DEBUG] - checkForCampsTimer_secondsInterval = " + checkForCampsTimer_secondsInterval)
        }
    }

	protected void DEF_DetectDynamicCamp_PlaySoundNoise_Stop()
	{
        StopSoundSet( m_DetectionSound );
        checkForCampsTimer.Stop();
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

    static void DEF_AddCampToList(vector position)
    {
        if(!DEF_IsVectorZero(position))
        {
            for (int i = 0; i < s_ActiveDynamicCamps.Count(); i++)
            {
                if (s_ActiveDynamicCamps[i] == position)    //uniqueness check
                    return;
            }

            TransmitterBase.s_ActiveDynamicCamps.Insert(position);
            if (debug)
            {
                Print("[DEF DEBUG] - Added camp to list at: " + position);
            }
        }
    }

    static void DEF_RemoveCampFromList(vector position)
    {
        if(!DEF_IsVectorZero(position))
        {
            int index = -1;
            for (int i = 0; i < s_ActiveDynamicCamps.Count(); i++)
            {
                if (DEF_IsVectorEqual(s_ActiveDynamicCamps[i], position))
                {
                    index = i;
                    break;
                }
            }

            if (index != -1)
            {
                s_ActiveDynamicCamps.Remove(index);

                if (debug)
                {
                    Print("[DEF DEBUG] - Removed camp at: " + position);
                }
            }
            else
            {
                if (debug)
                {
                    Print("[DEF DEBUG] - No camp found to remove at: " + position);
                }
            }
        }
    }

    protected void DEF_CheckForCamps()
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

        float closestDistance = 999999; //Used to not play multiple sound for different camps in range
        foreach (vector campPos : TransmitterBase.s_ActiveDynamicCamps)
        {
            float distance = vector.Distance(GetPosition(), campPos);
            if (distance < closestDistance)
                closestDistance = distance;
        }

        foreach (int threshold : distanceThresholds)
        {
            if (closestDistance < threshold)
            {
                string distanceBasedSound = SOUND_CAMP_DETECTED + threshold;
                PlaySoundSet(m_DetectionSound, distanceBasedSound, 1.0, 1.0);

                if (debug)
                {
                    Print("PLAYING: " + distanceBasedSound + " (closest camp)");
                }
                
                break;
            }
        }
    }
}