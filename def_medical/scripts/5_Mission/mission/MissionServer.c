modded class MissionServer
{
	override void OnInit()
	{
		GetMedicineConfig();
		super.OnInit();
		Print("[DynamicEventFramework] OnInit - Loaded config successfully.");
	}
}