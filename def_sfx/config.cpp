class CfgPatches
{
	class DynamicEventFramework_SFX
	{
		requiredAddons[]={ "DynamicEventFramework_Structures" };
		units[] = {};
		weapons[] = {};
	};
};

class CfgMods
{
	class DynamicEventFramework_SFX
	{
		dir= "DynamicEventFramework";
		type = "mod";
		author = "Traqu";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"DynamicEventFramework/def_sfx/scripts/4_world"};
			};
		};
	};
};

class CfgVehicles
{
	class DEF_DynamicEventObject;

	class DynamicEventSound: DEF_DynamicEventObject	{};

	class DEF_SFX_RadioChatter_DE: DynamicEventSound {};
};

class CfgSoundSets
{
	class DEF_SFX_RadioChatter_DE_SoundSet
	{
		soundShaders[] = {"DEF_SFX_RadioChatter_DE_SoundShader"};
	};
};

class CfgSoundShaders
{
	class DEF_SFX_RadioChatter_DE_SoundShader
	{
		samples[] = {{"DynamicEventFramework\def_sfx\data\sounds\environment\ambient\radio-chatter-relief-needed", 1}};
		range = 50;
		volume = 1;
		rangeCurve[] = {{0,1},{15,0.8},{20,0.75},{30,0.5},{40,0.25},{50,0.1}};
	};
};
