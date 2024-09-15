modded class ModifiersManager
{
	override void Init()
	{
		super.Init();
		AddModifier(new DexamphetamineMdfr);
		AddModifier(new AdderallInjectionMdfr);
		AddModifier(new AdderallComsumptionMdfr);
		AddModifier(new PrimobolanMdfr);
	}
};