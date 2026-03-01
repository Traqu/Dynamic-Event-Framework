class CfgPatches
{
	class DynamicEventFramework_Ores
	{
		units[]={};

		requiredVersion=0.1;
		requiredAddons[]= {};
	};
};

class CfgMods
{
	class DynamicEventFramework_Ores
	{
		dir = "DynamicEventFramework";
		type = "mod";
		dependencies[] = {"World"};

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"DynamicEventFramework/def_ores/Scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;

	class DEF_Powder_Base: Inventory_Base
	{
		scope=0;
		model="\DynamicEventFramework\def_ores\data\mist\Powder.p3d"
		weight=300;
		itemSize[]={1,1};

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=80;
					healthLevels[]={{1,{}}, {0.69999999, {}}, {0.5, {}}, {0.30000001, {}}, {0, {}}};
				};
			};
		};
	}

	class DEF_Chunk_Base: Inventory_Base
	{
		scope=0;
		// animClass = "Knife";
		model="\dz\gear\consumables\Stone.p3d";
		animClass="NoFireClass";
		weight=1500;
		itemSize[]={2,2};
		isMeleeWeapon=1;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{

						{
							1,

							{
								"DZ\gear\consumables\data\stone.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\consumables\data\stone.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\consumables\data\stone_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\consumables\data\stone_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\consumables\data\stone_destruct.rvmat"
							}
						}
					};
				};
			};
		};

		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundset = "pickUpHammer_Soundshader";
				};

				class drop
				{
					soundset = "ice_drop_SoundShader";
				};
			};
		};
	};

	class DEF_Shard_Base: Inventory_Base
	{
		scope = 0;
		animClass = "Knife";
		rotationFlags = 17;
		weight = 300;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=5;
		varQuantityDestroyOnMin=1;
		varStackMax=5
		itemSize[] = {1,1};

		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundset = "pickUpHammer_Soundshader";
				};

				class drop
				{
					soundset = "ice_drop_SoundShader";
				};
			};
		};
	};

	//scope=2;

	class Gunpowder_DEF: DEF_Powder_Base
	{
		scope=2;
		displayName = "$STR_Gunpowder0";
		descriptionShort = "$STR_Gunpowder1";
	};

	class Obsidian_Shard_DEF: DEF_Shard_Base
	{
		scope = 2;
		displayName = "$STR_ObsidianShard0";
		descriptionShort = "$STR_ObsidianShard1";
		model = "\DynamicEventFramework\def_ores\data\shards\obsidian\obsidian.p3d";
	};

	class Obsidian_Chunk_DEF: DEF_Chunk_Base
	{
		scope = 2;
		displayName = "$STR_ObsidianChunk0";
		descriptionShort = "$STR_ObsidianChunk1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"DynamicEventFramework\def_ores\data\shards\obsidian\obs_co.paa"};
	};
};