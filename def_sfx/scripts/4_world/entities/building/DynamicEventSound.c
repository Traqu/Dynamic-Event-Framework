class DynamicEventSound extends DynamicEventObject
{
	EffectSound m_AmbientSoundLoop;

	override void EEInit()
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			string m_SoundSet = this.GetType() + "_SoundSet";

			if ( m_SoundSet )
			{
				PlaySoundSetLoop( m_AmbientSoundLoop, m_SoundSet, 0, 0 );
			}
		}
	}
	
	override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			if ( m_AmbientSoundLoop )
			{
				SEffectManager.DestroyEffect(m_AmbientSoundLoop);
			}
		}
	}
};
