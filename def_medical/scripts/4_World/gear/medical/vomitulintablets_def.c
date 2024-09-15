/**
 * The `OnConsume` function of the `VomitulinTablets_DEF` class in DayZ mod removes specific agents,
 * triggers vomiting symptom, and adjusts energy and water stats of the player consuming the tablets.
 */
class VomitulinTablets_DEF : Edible_Base
{
    override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionEatTabletFromWrapper);
	}
	
	override void OnConsume(float amount, PlayerBase consumer)
	{

		consumer.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);

        float currentWater = consumer.GetStatWater().Get();
		float currentEnergy = consumer.GetStatEnergy().Get();

        consumer.GetStatEnergy().Add(-1 * currentEnergy * 0.6);
        consumer.GetStatWater().Add(-1 * currentWater * 0.8);
		
		consumer.RemoveAgent(eAgents.CHOLERA);
		consumer.RemoveAgent(eAgents.SALMONELLA);
		
        ModifiersManager modifiersManager = consumer.GetModifiersManager();

		if (modifiersManager.IsModifierActive(eModifiers.MDF_CHOLERA))
		    modifiersManager.DeactivateModifier(eModifiers.MDF_CHOLERA);

		if (modifiersManager.IsModifierActive(eModifiers.MDF_SALMONELLA))
		    modifiersManager.DeactivateModifier(eModifiers.MDF_SALMONELLA);
	}
}