class DEF_ContaminatedArea_DE: House
{
    EffectArea contaminatedArea;

    override void EEInit()
    {
        super.EEInit();
        InitializeArea(10, 10, 10);	    //? Radius, posHeight, negHeight
    }

    override void EEDelete( EntityAI parent )
    {
        if ( GetGame().IsDedicatedServer() && contaminatedArea )
        {
            contaminatedArea.Delete();
        }
        if ( parent )
        {
    		super.EEDelete( parent );
        }
    }

    protected void InitializeArea(int radius, int positiveHeight, int negativeHeight, int innerRings = 1, int innerSpacing = 3, int outerSpacing = 5, int outerRingOffset = 0)
    {
        SetAreaValues(radius, positiveHeight, negativeHeight, innerRings, innerSpacing, outerSpacing, outerRingOffset);
    }

    private void SetAreaValues(int radius, int positiveHeight, int negativeHeight, int innerRings, int innerSpacing, int outerSpacing, int outerRingOffset)
    {
        if ( GetGame().IsDedicatedServer() )
        {
            if (contaminatedArea)
            {
                contaminatedArea.Delete();
                contaminatedArea = null;
            }

            EffectAreaParams params = new EffectAreaParams();
            params.m_ParamName = "DynamicEventZone";
            params.m_ParamTriggerType = "ContaminatedTrigger";
            params.m_ParamRadius = radius;
            params.m_ParamPosHeight = positiveHeight;
            params.m_ParamNegHeight = negativeHeight;
            params.m_ParamInnerRings = innerRings;
            params.m_ParamInnerSpace = innerSpacing;
            params.m_ParamOuterToggle = 1;
            params.m_ParamOuterSpace = outerSpacing;
            params.m_ParamOuterOffset = outerRingOffset;
            params.m_ParamVertLayers = 0;
            params.m_ParamVerticalOffset = 0;
            params.m_ParamPartId = ParticleList.GetParticleID("graphics/particles/contaminated_area_gas_bigass");
            params.m_ParamAroundPartId = ParticleList.GetParticleID("graphics/particles/contaminated_area_gas_around");
            params.m_ParamTinyPartId = ParticleList.GetParticleID("graphics/particles/contaminated_area_gas_around_tiny");

            contaminatedArea = EffectArea.Cast(GetGame().CreateObjectEx("ContaminatedArea_Static", GetPosition(), ECE_NONE));
            if (contaminatedArea)
            {
                contaminatedArea.SetupZoneData(params);
            }
            else
            {
                Print("[ERROR] Could not created 'ContaminatedArea_Static'!");
            }
        }
    }

    protected void EEInit_SkipThis()
    {
        super.EEInit();
    }
}