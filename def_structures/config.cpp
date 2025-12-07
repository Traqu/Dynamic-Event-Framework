class CfgPatches
{
	class DynamicEventFramework_Structures
	{
        units[]={};

        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]={ "DZ_Structures" };
	};
};

class CfgMods
{
	class DynamicEventFramework_Structures
	{
		dir = "DynamicEventFramework";
		credits = "JHNY(kubush) - help with gamelabs integration";
		author = "Traqu";
		authorID = "76561198066157113";
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"DynamicEventFramework/def_structures/Scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
    //0. BASE
    class HouseNoDestruct;

    class DynamicEventObject : HouseNoDestruct
    {
        scope=1;    //TODO (if persistence issued occur) ~Sumrak - https://discord.com/channels/452035973786632194/499468381960011797/661593561141346314
        storageCategory=4;
    };

    //*  C:\Users\USER\Documents\DayZ Projects\DZ\structures\wrecks → check ancestors.
    //*  This is the only solution that worked for me to inherit animations after 1.26. update; pointing to a `model path` stopped working...
    //! ANIMATED ↓
    //1.
    class ContainerLockedBase: HouseNoDestruct{};
    class Land_Container_1Mo: HouseNoDestruct{};
    class Land_Container_1Moh: HouseNoDestruct{};
    class Land_Wreck_S1023_Blue : HouseNoDestruct{};


    class Land_Misc_Toilet_Mobile: HouseNoDestruct{};

    //TODO → add missing vehicles
    class Land_Wreck_Car_TwoDoors: HouseNoDestruct{};
    class Land_Wreck_Car_ThreeDoors: HouseNoDestruct{};
    class Land_Wreck_offroad02_aban1: HouseNoDestruct{};
    class Land_Wreck_offroad02_aban2: HouseNoDestruct{};
	class Land_Wreck_hb01_aban1_police: HouseNoDestruct{};
	class Land_wreck_truck01_aban1_blue: HouseNoDestruct{};
	class Land_wreck_truck01_aban2_blue: HouseNoDestruct{};

	class Land_wreck_sed02_aban1_police_DE: HouseNoDestruct{};  //? Sakhal specific
	class Land_wreck_sed02_aban2_police_DE: HouseNoDestruct{};  //? Sakhal specific
    class Land_Boat_Small9: HouseNoDestruct{};                  //? Sakhal specific
    class Land_Ship_Medium2: HouseNoDestruct{};                 //? Sakhal specific

    //2.
    class Land_ContainerLocked_Blue_DE: ContainerLockedBase{};
    class Land_ContainerLocked_Orange_DE: ContainerLockedBase{};
    class Land_ContainerLocked_Red_DE: ContainerLockedBase{};
    class Land_ContainerLocked_Yellow_DE: ContainerLockedBase{};
    class Land_Wreck_sed01_aban1_police: Land_Wreck_hb01_aban1_police{};
	class Land_wreck_truck01_aban1_firetruck: Land_wreck_truck01_aban1_blue{};
	class Land_wreck_truck01_aban1_orange: Land_wreck_truck01_aban1_blue{};
    class Land_Wreck_S1023_Medic_Beige : Land_Wreck_S1023_Blue{};

    //3.
    class Land_Wreck_hb01_aban1_green_DE: Land_Wreck_Car_TwoDoors{};
    class Land_Wreck_hb01_aban1_white_DE: Land_Wreck_Car_TwoDoors{};
    class Land_Wreck_hb02_aban1_blue_DE: Land_Wreck_Car_ThreeDoors{};
    class Land_Wreck_offroad02_aban1_DE: Land_Wreck_offroad02_aban1{};
    class Land_Wreck_offroad02_aban2_DE: Land_Wreck_offroad02_aban2{};
    class Land_Wreck_sed01_aban1_black_DE: Land_Wreck_Car_ThreeDoors{};
    class Land_Wreck_sed01_aban1_police_DE: Land_Wreck_Car_ThreeDoors{};
    class Land_Wreck_sed01_aban2_white_DE: Land_Wreck_Car_ThreeDoors{};
    class Land_Wreck_sed02_aban2_grey_DE: Land_Wreck_Car_ThreeDoors{};
    class Land_Wreck_sed02_aban2_yellow_DE: Land_Wreck_Car_ThreeDoors{};
    class Land_wreck_truck01_aban1_firetruck_DE: Land_wreck_truck01_aban1_firetruck{};
    class Land_wreck_truck01_aban1_orange_DE: Land_wreck_truck01_aban1_orange{};
	class Land_wreck_truck01_aban2_firetruck: Land_wreck_truck01_aban1_firetruck{};
    class Land_wreck_truck01_aban2_green_DE: Land_wreck_truck01_aban2_blue{};
    class Land_Wreck_S1023_Medic_Beige_DE : Land_Wreck_S1023_Medic_Beige{};

    ///4.
    class Land_wreck_truck01_aban2_firetruck_DE: Land_wreck_truck01_aban2_firetruck{};
    //!Animated ↑

    //* StaritingPoints.
    class DEF__Starting_Point_NO_DISPLAY_DE: DynamicEventObject{}; //? This one proved to be useful so I am adding it; has no script to it so will not be displayd on map.

    class DEF__Starting_Point_Base_DE: DynamicEventObject
    {
        eventPictogram = "question";
        displayedName = "Dynamic event";
    };

    class DEF__Starting_Point_AC130JCrash_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "plane";
        displayedName = "Plane crash";
    };

    class DEF__Starting_Point_Asteroid_DE: DEF__Starting_Point_Base_DE
    {
        eventPictogram = "meteor";
        displayedName = "Meteorite";
    };

    class DEF__Starting_Point_HuntingCamp_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "campfire";
        displayedName = "Survivor camp";
    };

    class DEF__Starting_Point_Industrial_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "truck-container";
        displayedName = "Industrial event";
    };

    class DEF__Starting_Point_MedicalConvoy_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "ambulance";
        displayedName = "Medical convoy";
    };

    class DEF__Starting_Point_MedicalMiscalenous_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "hand-holding-medical";
        displayedName = "Medical";
    };

    class DEF__Starting_Point_MilitaryTents_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "campground";
        displayedName = "Military tents";
    };

    class DEF__Starting_Point_Roadblock_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "minus-octagon";
        displayedName = "Roadblock";
    };

    class DEF__Starting_Point_Paratrooper_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "scarecrow";
        displayedName = "Hanged paratrooper";
    };

    class DEF__Starting_Point_Raft_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "anchor";
        displayedName = "Shoal boat";
    };

    class DEF__Starting_Point_Boat_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "anchor";
        displayedName = "Boat";
    };

    class DEF__Starting_Point_Shipwreck_DE : DEF__Starting_Point_Base_DE
    {
        eventPictogram = "ship";
        displayedName = "Container ship";
    };

    //! Displayables ↓
    //? Sakhal specific
    class DEF_Displayable_Land_Wreck_S1023_Medic_Beige_DE: Land_Wreck_S1023_Medic_Beige_DE
    {
        scope=1;
        storageCategory=4; //Kept to stay consistent
    };

    class DEF_Displayable_Container_1Moh_DE: Land_Container_1Moh //!Animated
    {
        scope=1;
        storageCategory=4;
        eventPictogram = "container-storage";
        displayedName = "Washed container";
    };

    //? Sakhal specific
    class DEF_Displayable_ContainerLocked_Blue_DE: Land_ContainerLocked_Blue_DE //!Animated
    {
        scope=1;
        storageCategory=4;
        eventPictogram = "container-storage";
        displayedName = "Washed container";
    };

    //? Sakhal specific
    class DEF_Displayable_ContainerLocked_Orange_DE: Land_ContainerLocked_Orange_DE //!Animated
    {
        scope=1;
        storageCategory=4;
        eventPictogram = "container-storage";
        displayedName = "Washed container";
    };

    //? Sakhal specific
    class DEF_Displayable_ContainerLocked_Red_DE: Land_ContainerLocked_Red_DE //!Animated
    {
        scope=1;
        storageCategory=4;
        eventPictogram = "container-storage";
        displayedName = "Washed container";
    };

    //? Sakhal specific
    class DEF_Displayable_ContainerLocked_Yellow_DE: Land_ContainerLocked_Yellow_DE //!Animated
    {
        scope=1;
        storageCategory=4;
        eventPictogram = "container-storage";
        displayedName = "Washed container";
    };

    //? Sakhal specific
    class DEF_Displayable_FrozenScientist_DE: DEF__Starting_Point_Base_DE //* Not-animated
    {
        model="DZ\characters\zombies\Static_FrozenScientist.p3d";
        eventPictogram = "head-side-virus";
        displayedName = "Frozen scientist";
    };

    //? Sakhal specific
    class DEF_Displayable_Wreck_sed02_aban1_Police_DE: Land_wreck_sed02_aban1_police_DE //!Animated
    {
        scope=1;
        storageCategory=4;
        eventPictogram = "taxi";
        displayedName = "Police car";
    };

    //? Sakhal specific
    class DEF_Displayable_Wreck_sed02_aban2_Police_DE: Land_wreck_sed02_aban2_police_DE //!Animated
    {
        scope=1;
        storageCategory=4;
        eventPictogram = "taxi";
        displayedName = "Police car";
    };
    //!Displayables ↑

    //* GenericObjects.
    class DEF_Ammoboxes_Big_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\underground\storage\proxy\ammoboxes_big.p3d";
    };

    class DEF_Ammoboxes_Single_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\underground\storage\proxy\ammoboxes_single.p3d";
    };

    class DEF_Ammoboxes_Stacked_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\underground\storage\proxy\ammoboxes_stacked.p3d";
    };

    class DEF_Animal_Guts_DE: DynamicEventObject
    {
        model="DZ\gear\food\animal_guts.p3d";
    };

    class DEF_Concrete_Panel_DE: DynamicEventObject
    {
        model="DZ\structures\roads\panels\panel_concrete_1.p3d";
    };

    class DEF_Concrete_Panel_Damaged_DE: DynamicEventObject
    {
        model="DZ\structures\roads\panels\panel_concrete_dam.p3d";
    };

    class DEF_Concrete_Panel_2_DE: DynamicEventObject
    {
        model="DZ\structures\roads\panels\panel_concrete_2.p3d";
    };

    class DEF_Concrete_Panels_DE: DynamicEventObject
    {
        model="DZ\structures\roads\panels\panels_concrete.p3d";
    };

    class DEF_Concrete_Path_DE: DynamicEventObject
    {
        model="DZ\structures\roads\panels\path_panels.p3d";
    };

    class DEF_Concrete_Path_Damaged_DE: DynamicEventObject
    {
        model="DZ\structures\roads\panels\path_panels_damaged.p3d";
    };

    class DEF_Container_1Mo_DE: Land_Container_1Mo  //!Animated
    {
        scope=1;
        storageCategory=4;
    };

    class DEF_Container_1Moh_DE: Land_Container_1Moh  //!Animated
    {
        scope=1;
        storageCategory=4;
    };

    class DEF_Dead_MassGrave_15m_DE: DynamicEventObject
    {
        model="DZ\structures\specific\deadbodies\dead_massgrave_15m.p3d";
    };

    class DEF_Dead_Pile1_DE: DynamicEventObject
    {
        model="DZ\structures\specific\deadbodies\dead_pile1.p3d";
    };

    class DEF_Dead_Pile2_DE: DynamicEventObject
    {
        model="DZ\structures\specific\deadbodies\dead_pile2.p3d";
    };

    class DEF_Dead_Pile3_DE: DynamicEventObject
    {
        model="DZ\structures\specific\deadbodies\dead_pile3.p3d";
    };

    class DEF_Dead_Pile4_DE: DynamicEventObject
    {
        model="DZ\structures\specific\deadbodies\dead_pile4.p3d";
    };

    class DEF_Decal_Damage_Long2_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_damage_long2.p3d";
    };

    class DEF_Decal_Damage_Long3_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_damage_long3.p3d";
    };

    class DEF_Decal_Damage_Long4_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_damage_long4.p3d";
    };

    class DEF_Decal_Damage_Medium1_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_damage_medium1.p3d";
    };

    class DEF_Decal_Damage_Medium2_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_damage_medium2.p3d";
    };

    class DEF_Decal_Dirt_Rocks2_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\roads\decals\decal_dirt_rocks2.p3d";
    };

    class DEF_Decal_Heli_Army_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_heli_army.p3d";
    };

    class DEF_Decal_Oilstain1_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\roads\decals\decal_oilstain1.p3d";
    };

    class DEF_Decal_Oilstain2_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\roads\decals\decal_oilstain2.p3d";
    };

    class DEF_Decal_Oilstain3_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\roads\decals\decal_oilstain3.p3d";
    };

    class DEF_Decal_Oilstain4_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\roads\decals\decal_oilstain4.p3d";
    };

    class DEF_Decal_Runway_Skidmarks_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_runway_skidmarks.p3d";
    };

    class DEF_Decal_Runway_Skidmarks_End_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_runway_skidmarks_end.p3d";
    };

    class DEF_Decal_Runway_Skidmarks_End2_DE: DynamicEventObject
    {
        model="DZ\structures\roads\decals\decal_runway_skidmarks_end2.p3d";
    };

    class DEF_Decon_HazmatBag_01_F_DE: DynamicEventObject
    {
        model="DZ\structures\residential\medical\decon_hazmatbag_01_f.p3d";
    };

    class DEF_Decon_LayFlatHose_01_CurveLong_F_DE: DynamicEventObject
    {
        model="DZ\structures\residential\medical\decon_layflathose_01_curvelong_f.p3d";
    };

    class DEF_Decon_LayFlatHose_01_Roll_F_DE: DynamicEventObject
    {
        model="DZ\structures\residential\medical\decon_layflathose_01_roll_f.p3d";
    };

    class DEF_Decon_LayFlatHose_01_SBend_F_DE: DynamicEventObject
    {
        model="DZ\structures\residential\medical\decon_layflathose_01_sbend_f.p3d";
    };

    class DEF_Farm_Manurepile_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\industrial\farms\farm_manurepile.p3d";
    };

    class DEF_FireExtinguisher_DE: DynamicEventObject
    {
        model="DZ\gear\tools\fireextinguisher.p3d";
    };

    class DEF_Forest_HumanSkeleton_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\specific\forest\forest_humanskeleton.p3d";
    };

    class DEF_Garbage_Bin_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\garbage_bin.p3d";
    };

    class DEF_Garbage_Container_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\garbage_container.p3d";
    };

    class DEF_Garbage_GroundSq_3m_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\garbage_groundsq_3m.p3d";
    };

    class DEF_Garbage_GroundSq_5m_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\garbage_groundsq_5m.p3d";
    };

    class DEF_Garbage_GroundSq_5m_NoLC_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\garbage_groundsq_5m_nolc.p3d";
    };

    class DEF_Garbage_Pile2_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\garbage_pile2.p3d";
    };

    class DEF_Garbage_Pile3_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\garbage_pile3.p3d";
    };

    class DEF_Garbage_Pile7_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\residential\misc\garbage_pile7.p3d";
    };

    class DEF_HBarrier_1m_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\proxy\hbarrier_1m.p3d";
    };

    class DEF_HBarrier_4m_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\hbarrier_4m.p3d";
    };

    class DEF_HBarrier_6m_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\hbarrier_6m.p3d";
    };

    class DEF_HBarrier_Round_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\hbarrier_round.p3d";
    };

    class DEF_Land_Mil_Tent_Big1_1_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big1_1.p3d";
    };

    class DEF_Land_Mil_Tent_Big1_2_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big1_2.p3d";
    };

    class DEF_Land_Mil_Tent_Big1_3_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big1_3.p3d";
    };

    class DEF_Land_Mil_Tent_Big1_4_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big1_4.p3d";
    };

    class DEF_Land_Mil_Tent_Big1_5_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big1_5.p3d";
    };

    class DEF_Land_Mil_Tent_Big2_1_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big2_1.p3d";
    };

    class DEF_Land_Mil_Tent_Big2_2_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big2_2.p3d";
    };

    class DEF_Land_Mil_Tent_Big2_3_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big2_3.p3d";
    };

    class DEF_Land_Mil_Tent_Big2_4_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big2_4.p3d";
    };

    class DEF_Land_Mil_Tent_Big2_5_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big2_5.p3d";
    };

    class DEF_Land_Mil_Tent_Big3_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big3.p3d";
    };

    class DEF_Land_Mil_Tent_Big4_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_tent_big4.p3d";
    };

    class DEF_Land_Mil_Guardshed_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_guardshed.p3d";
    };

    class DEF_Medical_CURCylinder_01_F_DE: DynamicEventObject
    {
        model="DZ\structures\Residential\Medical\CURCylinder_01_F.p3d";
    };

    class DEF_Medical_Furniture_Hospital_Transport_Bed_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\hospital_transport_bed\hospital_transport_bed.p3d";
    };

    class DEF_Medical_Furniture_Lab_Beaker_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_beaker.p3d";
    };

    class DEF_Medical_Furniture_Lab_Bunsen_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_bunsen.p3d";
    };

    class DEF_Medical_Furniture_Lab_Cylinder_Beaker_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_cylinder_beaker.p3d";
    };

    class DEF_Medical_Furniture_Lab_Dropper_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_dropper.p3d";
    };

    class DEF_Medical_Furniture_Lab_Erlenmeyer_Flask_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_erlenmeyer_flask.p3d";
    };

    class DEF_Medical_Furniture_Lab_Microscope_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_microscope.p3d";
    };

    class DEF_Medical_Furniture_Lab_Petri_Dish_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_petri_dish.p3d";
    };

    class DEF_Medical_Furniture_Lab_Vial_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_vial.p3d";
    };

    class DEF_Medical_Furniture_Lab_Volume_Beaker_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\school_equipment\lab_volume_beaker.p3d";
    };

    class DEF_Medical_Furniture_Patient_Monitor_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\medical\patient_monitor\patient_monitor.p3d";
    };

    class DEF_Medical_Furniture_Shelfs_Blue_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\various\shelf_dz.p3d";
    };

    class DEF_Medical_Furniture_Shelfs_Brown_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\ruins\proxy\shelfs_small.p3d";
    };

    class DEF_Medical_Furniture_Table_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\medical\medical_table\medical_table.p3d";
    };

    class DEF_Medical_Stretcher_Green_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\beds\stretcher_green.p3d";
    };

    class DEF_Medical_Stretcher_Green_Folded_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\beds\stretcher_green_folded.p3d";
    };

    class DEF_Medical_Stretcher_Red_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\beds\stretcher_red.p3d";
    };

    class DEF_Medical_Stretcher_Red_Folded_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\beds\stretcher_red_folded.p3d";
    };

    class DEF_Metalcrate_02_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\cases\metalcrate_02\metalcrate_02.p3d";
    };

    class DEF_Metalcrate_DE: DynamicEventObject
    {
        model="DZ\structures\furniture\cases\metalcrate\metalcrate.p3d";
    };

    class DEF_Mil_Artilery_Rampart_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_artilery_rampart.p3d";
    };

    class DEF_Mil_Artillery_Nest_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_artillery_nest.p3d";
    };

    class DEF_Mil_Camonet_Big_East_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_camonet_big_east.p3d";
    };


    class DEF_Mil_Camonet_Big_West_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_camonet_big_west.p3d";
    };


    class DEF_Mil_Camonet_Roof_East_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_camonet_roof_east.p3d";
    };


    class DEF_Mil_Camonet_Roof_West_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_camonet_roof_west.p3d";
    };


    class DEF_Mil_Camonet_Side_East_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_camonet_side_east.p3d";
    };


    class DEF_Mil_Camonet_Side_West_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\mil_camonet_side_west.p3d";
    };

     class DEF_Mil_Guardtower_DE: DynamicEventObject
    {
        model="DZ\structures\military\houses\mil_guardtower.p3d";
    };

    class DEF_Misc_Bagfence_3m_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_bagfence_3m.p3d";
    };

    class DEF_Misc_Bagfence_Corner_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_bagfence_corner.p3d";
    };

    class DEF_Misc_Bagfence_Round_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_bagfence_round.p3d";
    };

    class DEF_Misc_Barbedwire_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_barbedwire.p3d";
    };

    class DEF_Misc_BoxWooden_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\misc_boxwooden.p3d";
    };

    class DEF_Misc_Chair_Camp1_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\misc_chair_camp1.p3d";
    };

    class DEF_Misc_Chair_Camp2_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\misc_chair_camp2.p3d";
    };

    class DEF_Misc_Chair_Plastic_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\misc_chair_plastic.p3d";
    };

    class DEF_Misc_ConcreteBlock2_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_concreteblock2.p3d";
    };

    class DEF_Misc_ConcreteBlock2_Damaged_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_concreteblock2_damaged.p3d";
    };

    class DEF_Misc_DragonTeeth_Single_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\military\misc\misc_dragonteeth_single.p3d";
    };

    class DEF_Misc_Gunrack_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_gunrack.p3d";
    };

    class DEF_Misc_Pallet_DE: DynamicEventObject
    {
        model="DZ\structures\industrial\misc\misc_pallet.p3d";
    };

    class DEF_Misc_Pallets1_DE: DynamicEventObject
    {
        model="DZ\structures\industrial\misc\misc_pallets1.p3d";
    };

    class DEF_Misc_Pallets2_DE: DynamicEventObject
    {
        model="DZ\structures\industrial\misc\misc_pallets2.p3d";
    };

    class DEF_Misc_Pallets3_DE: DynamicEventObject
    {
        model="DZ\structures\industrial\misc\misc_pallets3.p3d";
    };

    class DEF_Misc_Razorwire_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_razorwire.p3d";
    };

    class DEF_Misc_RoadBarrier_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\misc_roadbarrier.p3d";
    };

    class DEF_Misc_SupplyBox1_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_supplybox1.p3d";
    };

    class DEF_Misc_SupplyBox2_DE: DynamicEventObject
    {
        model="DZ\structures\military\misc\misc_supplybox2.p3d";
    };

    class DEF_Misc_Table_Camp_Small_DE: DynamicEventObject
    {
        model="C:\Users\piotr\Documents\DayZ Projects\DZ\structures\residential\misc\misc_table_camp_small.p3d";
    };

    class DEF_Misc_Tirepile_Group_DE: DynamicEventObject
    {
        model="DZ\structures\industrial\misc\misc_tirepile_group.p3d";
    };

    class DEF_Misc_Toilet_Mobile_DE: Land_Misc_Toilet_Mobile  //!Animated
    {
        scope=1;
        storageCategory=4;
    };

    class DEF_Misc_WoodenCrate_3x_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\residential\misc\misc_woodencrate_3x.p3d";
    };

    class DEF_Misc_WoodenCrate_5x_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\residential\misc\misc_woodencrate_5x.p3d";
    };

    class DEF_Misc_Woodtable_Indoor_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\misc_woodtable_indoor.p3d";
    };

    class DEF_Misc_Woodtable_Outdoor_DE: DynamicEventObject
    {
        model="DZ\structures\residential\misc\misc_woodtable_outdoor.p3d";
    };

    class DEF_Roadblock_Bags_Curve_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_bags_curve.p3d";
    };

    class DEF_Roadblock_Bags_EndL_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_bags_endl.p3d";
    };

    class DEF_Roadblock_Bags_EndR_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_bags_endr.p3d";
    };

    class DEF_Roadblock_Bags_Long_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_bags_long.p3d";
    };

    class DEF_Roadblock_CncBlock_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_cncblock.p3d";
    };

    class DEF_Roadblock_CncBlocks_Long_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_cncblocks_long.p3d";
    };

    class DEF_Roadblock_CncBlocks_Short_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_cncblocks_short.p3d";
    };

    class DEF_Roadblock_Pillbox_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_pillbox.p3d";
    };

    class DEF_Roadblock_Table_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_table.p3d";
    };

    class DEF_Roadblock_Wood_Long_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_wood_long.p3d";
    };

    class DEF_Roadblock_Wood_Small_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_wood_small.p3d";
    };

    class DEF_Roadblock_WoodenCrate_DE: DynamicEventObject
    {
        model="DZ\structures\military\improvised\roadblock_woodencrate.p3d";
    };

    class DEF_Rubble_DirtPile_Large_DE: DynamicEventObject
    {
        model="DZ\structures\ruins\rubble_dirtpile_large.p3d";
    };

    class DEF_Rubble_Glass_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\proxy\rubble_glass.p3d";
    };

    class DEF_ShellCrater1_Decal_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\military\training\shellcrater1_decal.p3d";
    };

    class DEF_ShellCrater2_Debris_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\military\training\shellcrater2_debris.p3d";
    };

    class DEF_ShellCrater2_Small_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\military\training\shellcrater2_small.p3d";
    };

    class DEF_Sign_Enochmil_Warning1_Pl_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\signs\misc\sign_enochmil_warning1_pl.p3d";
    };

    class DEF_Sign_Roadblock_Arrow_DE: DynamicEventObject
    {
        model="DZ\structures\signs\misc\sign_roadblock_arrow.p3d";
    };

    class DEF_Sign_Roadblock_Stop_DE: DynamicEventObject
    {
        model="DZ\structures\signs\misc\sign_roadblock_stop.p3d";
    };

    class DEF_Wall_Barricade1_4_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\walls\wall_barricade1_4.p3d";
    };

    class DEF_Wall_CncBarrier_4Block_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\walls\wall_cncbarrier_4block.p3d";
    };

    class DEF_Wall_CncBarrier_Block_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\walls\wall_cncbarrier_block.p3d";
    };

    class DEF_Wall_MilCncBarrier_DE: DynamicEventObject
    {
        model="DZ\structures_bliss\walls\wall_milcncbarrier.p3d";
    };

    class DEF_Wall_Tincom_3_DE: DynamicEventObject
    {
        model="DZ\structures\walls\wall_tincom_3.p3d";
    };

    class DEF_Wall_Tincom_9_DE: DynamicEventObject
    {
        model="DZ\structures\walls\wall_tincom_9.p3d";
    };

    class DEF_Wall_Tincom_9_2_DE: DynamicEventObject
    {
        model="DZ\structures\walls\wall_tincom_9_2.p3d";
    };

    class DEF_Wall_Tincom_Pole_DE: DynamicEventObject
    {
        model="DZ\structures\walls\wall_tincom_pole.p3d";
    };

    class DEF_Wreck_BMP1_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_bmp1.p3d";
    };

    class DEF_Wreck_BMP2_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_bmp2.p3d";
    };

    class DEF_Wreck_BRDM_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_brdm.p3d";
    };

    class DEF_Wreck_AC130J_DE: DynamicEventObject
    {
        model="DynamicEventFramework\def_structures\data\watermark\J.p3d";
        // model="DZ\structures\wrecks\Aircraft\Wreck_C130J.p3d";
    };

    class DEF_Wreck_AC130J_2_DE: DynamicEventObject
    {
        model="DynamicEventFramework\def_structures\data\watermark\J2.p3d";
        // model="DZ\structures\wrecks\Aircraft\Wreck_C130J_2.p3d";
    };

    class DEF_Wreck_AC130J_Cargo_DE: DynamicEventObject
    {
        model="DynamicEventFramework\def_structures\data\watermark\JCargo.p3d";
        // model="DZ\structures\wrecks\Aircraft\Wreck_C130J_Cargo.p3d";
    };

    //class DEF_Wreck_Ambulance_New_DE: DynamicEventObject
    //{
    //    model = "dynamiceventframework\def_structures\data\ambulancenew\ambulance.p3d";
	//	hiddenSelections[] = {"Body","Bottom","Dashboard","Lights","Plate","Wheels"};
	//	hiddenSelectionsTextures[] = {
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Body\Body_co.paa",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Bottom\UCB_BOTTOM_co.paa",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Dashboard\Material _31_co.paa",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Lights\SHVAN95_HEADLIGHTS_co.paa",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Plates\Numberplates_co.paa",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Wheels\RB7_StampedHorace_co.paa"
    //                            };
	//	hiddenSelectionsMaterials[] = {
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Body\TNL_Body.rvmat",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Bottom\TNL_Bottom.rvmat",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Dashboard\TNL_Dashboard.rvmat",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Lights\TNL_Lights.rvmat",
    //                            "dynamiceventframework\def_structures\data\ambulancenew\textures\Wheels\TNL_Wheels.rvmat"};
    //};

    class DEF_Wreck_Ambulance_Old_DE: DynamicEventObject
    {
        model="DynamicEventFramework\def_structures\data\ambulanceold\buchankamedi.p3d";
    };

    class DEF_Wreck_Decal_Big_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_decal_big.p3d";
    };

    class DEF_Wreck_Decal_Big_NoLC_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_decal_big_nolc.p3d";
    };

    class DEF_Wreck_Decal_Small1_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_decal_small1.p3d";
    };

    class DEF_Wreck_Decal_Small1_NoLC_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_decal_small1_nolc.p3d";
    };

    class DEF_Wreck_Decal_Small2_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_decal_small2.p3d";
    };

    class DEF_Wreck_Decal_Small2_NoLC_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_decal_small2_nolc.p3d";
    };

    class DEF_Wreck_HMMWV_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_hmmwv.p3d";
    };

    class DEF_Wreck_Ikarus_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_ikarus.p3d";
    };

    class DEF_Wreck_Mi8_Crashed_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\aircraft\wreck_mi8_crashed.p3d";
    };

    class DEF_Wreck_PowGen_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_powgen.p3d";
    };

    class DEF_Wreck_T72_Chassis_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_t72_chassis.p3d";
    };

    class DEF_Wreck_T72_Turret_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_t72_turret.p3d";
    };

    class DEF_Wreck_Uaz_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_uaz.p3d";
    };

    class DEF_Wreck_Ural_DE: DynamicEventObject
    {
        model="DZ\structures\wrecks\vehicles\wreck_ural.p3d";
    };

    class DEF_Wreck_Hb01_Aban1_Green_DE: Land_Wreck_hb01_aban1_green_DE  //!Animated
    {
        scope=1;
        storageCategory=4;
    };

    class DEF_Wreck_Hb01_Aban1_White_DE: Land_Wreck_Car_TwoDoors  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban1_white.p3d";
    };

    class DEF_Wreck_Hb02_Aban1_Blue_DE: Land_Wreck_Car_ThreeDoors  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_hb02_aban1_blue.p3d";
    };

    class DEF_Wreck_Offroad02_Aban1_DE: Land_Wreck_offroad02_aban1  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\wreck_offroad02_aban1.p3d";
    };

    class DEF_Wreck_Offroad02_Aban2_DE: Land_Wreck_offroad02_aban2  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\wreck_offroad02_aban2.p3d";
    };

    class DEF_Wreck_Sed01_Aban1_Black_DE: Land_Wreck_Car_ThreeDoors  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_black.p3d";
    };

    class DEF_Wreck_Sed01_Aban1_Police_DE: Land_Wreck_sed01_aban1_police  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_police.p3d";
    };

    class DEF_Wreck_Sed01_Aban2_White_DE: Land_Wreck_Car_ThreeDoors  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban2_white.p3d";
    };

    class DEF_Wreck_Sed02_Aban2_Grey_DE: Land_Wreck_Car_ThreeDoors  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban2_grey.p3d";
    };

    class DEF_Wreck_Sed02_Aban2_Yellow_DE: Land_Wreck_Car_ThreeDoors  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban2_yellow.p3d";
    };

    class DEF_Wreck_Truck01_Aban1_Firetruck_DE: Land_wreck_truck01_aban1_firetruck  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\wreck_truck01_aban1_firetruck.p3d";
    };

    class DEF_Wreck_Truck01_Aban1_Orange_DE: Land_wreck_truck01_aban1_orange  //!Animated
    {
        scope=1;
        storageCategory=4;
    };

    class DEF_Wreck_Truck01_Aban2_Firetruck_DE: Land_wreck_truck01_aban2_firetruck  //!Animated
    {
        scope=1;
        storageCategory=4;
    };

    class DEF_Land_Wreck_S1023_Medic_Beige_DE: Land_Wreck_S1023_Medic_Beige_DE  //!Animated //This class is no different than vanilla one, just added for convenience of navigation → if you want to display it on CF map, use the displayable variant
    {
        scope=1;
        storageCategory=4; //Kept to stay consistent
    };

    class DEF_Wreck_Truck01_Aban2_Green_DE: Land_wreck_truck01_aban2_blue  //!Animated
    {
        scope=1;
        storageCategory=4;
		model="\DZ\structures\Wrecks\Vehicles\wreck_truck01_aban2_green.p3d";
    };

//? INDUSTRIAL LOOT ↓

    class DEF_Wreck_Truck01_Aban1_Orange_INDUSTRIAL_DE: DEF_Wreck_Truck01_Aban1_Orange_DE{};    //!Animated    INDUSTRIAL PROTO
    class DEF_Wreck_Truck01_Aban1_Green_INDUSTRIAL_DE: DEF_Wreck_Truck01_Aban2_Green_DE{};      //!Animated    INDUSTRIAL PROTO

    class DEF_StaticObj_Wreck_Bulldozer_INDUSTRIAL_DE: DynamicEventObject
    {
        model="DZ\structures\Wrecks\Vehicles\Wreck_Bulldozer.p3d";
    };

    class DEF_StaticObj_Wreck_Digger_INDUSTRIAL_DE: DynamicEventObject
    {
        model="DZ\structures\Wrecks\Vehicles\Wreck_Digger.p3d";
    };

    class DEF_StaticObj_Wreck_Trailer_Flat_INDUSTRIAL_DE: DynamicEventObject
    {
        model="DZ\structures\Wrecks\Vehicles\Wreck_Trailer_Flat.p3d";
    };

    class DEF_Land_Wreck_Mining_Excavator_INDUSTRIAL_DE: DynamicEventObject
    {
        model="\DZ\structures_bliss\Wrecks\Vehicles\Wreck_Mining_Excavator.p3d";
    };

    class DEF_Land_Wreck_Mining_HaulTruck_INDUSTRIAL_DE: DynamicEventObject
    {
        model="\DZ\structures_bliss\Wrecks\Vehicles\Wreck_Mining_HaulTruck.p3d";
    };

//? INDUSTRIAL LOOT ↑

    class DEF_Land_Ship_Big_FrontA_DE : DynamicEventObject
    {
        model="\DZ\structures\Wrecks\Ships\Ship_Big_FrontA.p3d";
    };

    class DEF_Land_Ship_Big_FrontB_DE : DynamicEventObject
    {
        model="\DZ\structures\Wrecks\Ships\Ship_Big_FrontB.p3d";
    };

    class DEF_Land_Ship_Big_BackA_DE : DynamicEventObject
    {
        model="\DZ\structures\Wrecks\Ships\Ship_Big_BackA.p3d";
    };

    class DEF_Land_Ship_Big_BackB_DE : DynamicEventObject
    {
        model="\DZ\structures\Wrecks\Ships\Ship_Big_BackB.p3d";
    };

    class DEF_Land_Ship_Big_Castle_DE : DynamicEventObject
    {
        model="\DZ\structures\Wrecks\Ships\Ship_Big_Castle.p3d";
    };

    class DEF_StaticObj_Wreck_Ship_Medium_Front_DE : DynamicEventObject
    {
        model="DZ\structures\Wrecks\Ships\Ship_Medium_Front.p3d";
    };

    class DEF_StaticObj_Wreck_Ship_Medium_Back_DE : DynamicEventObject
    {
        model="DZ\structures\Wrecks\Ships\Ship_Medium_Back.p3d";
    };

    class DEF_Land_Ship_Medium2_DE : Land_Ship_Medium2 //!Animated
    {
        scope=1;
        storageCategory=4;
        model="DZ\structures_sakhal\wrecks\Ship_Medium2.p3d";
    };

    class DEF_StaticObj_Wreck_Ship_Big_Lifeboat_DE : DynamicEventObject
    {
        model="DZ\structures\Wrecks\Ships\Ship_Big_Lifeboat.p3d";
    };

    class DEF_Land_Boat_Small7_DE : DynamicEventObject
    {
        model="DZ\structures_sakhal\wrecks\Boat_Small7.p3d";
    };

    class DEF_Land_Boat_Small8_Blue_DE : DynamicEventObject
    {
        model="DZ\structures_sakhal\wrecks\Boat_Small8_Blue.p3d";
    };

    class DEF_Land_Boat_Small8_Red_DE : DynamicEventObject
    {
        model="DZ\structures_sakhal\wrecks\Boat_Small8_Red.p3d";
    };

    class DEF_Land_Boat_Small9_DE : Land_Boat_Small9 //!Animated
    {
        scope=1;
        storageCategory=4;
        model="DZ\structures_sakhal\wrecks\Boat_Small9.p3d";
    };

    class DEF_Land_Boat_Small10_Blue_DE : DynamicEventObject
    {
        model="DZ\structures_sakhal\wrecks\Boat_Small10_Blue.p3d";
    };

    class DEF_Land_Boat_Small10_Red_DE : DynamicEventObject
    {
        model="DZ\structures_sakhal\wrecks\Boat_Small10_Blue.p3d";
    };

    //* Particles.
    //? Fires.
    class DEF_PARTICLE_BONFIRE_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_CAMP_SMALL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_CAMP_NORMAL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_CAMP_STOVE_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_HOUSE_SMALL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_HOUSE_NORMAL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_BARREL_SMALL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_BARREL_NORMAL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_OVEN_SMALL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_OVEN_NORMAL_FIRE_DE: DynamicEventObject{};
    class DEF_PARTICLE_TORCH_T1_DE: DynamicEventObject{};
    class DEF_PARTICLE_TORCH_T2_DE: DynamicEventObject{};
    class DEF_PARTICLE_TORCH_T3_DE: DynamicEventObject{};
    //? Environmental.
    class DEF_PARTICLE_SPOOKY_MIST_DE: DynamicEventObject{};
    class DEF_PARTICLE_CONTAMINATED_AREA_GAS_BIGASS_DE: DynamicEventObject{};
    class DEF_PARTICLE_ENV_SWARMING_FLIES_DE: DynamicEventObject{};
    //? Smokes.
    class DEF_PARTICLE_BONFIRE_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_M18_BLACK_LOOP_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_M18_GREEN_LOOP_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_M18_PURPLE_LOOP_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_M18_RED_LOOP_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_M18_WHITE_LOOP_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_M18_YELLOW_LOOP_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_RDG2_BLACK_LOOP_DE: DynamicEventObject{};
    class DEF_PARTICLE_GRENADE_RDG2_WHITE_LOOP_DE: DynamicEventObject{};
    class DEF_PARTICLE_HATCHBACK_COOLANT_OVERHEATED_DE: DynamicEventObject{};
    class DEF_PARTICLE_HATCHBACK_ENGINE_OVERHEATED_DE: DynamicEventObject{};
    class DEF_PARTICLE_POWER_GENERATOR_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_ROADFLARE_BURNING_SMOKE_DE: DynamicEventObject{};
    class DEF_PARTICLE_SMOKE_GENERIC_WRECK_DE: DynamicEventObject{};
    class DEF_PARTICLE_SMOKING_CAR_ENGINE_DE: DynamicEventObject{};
    class DEF_PARTICLE_SMOKING_HELI_WRECK_DE: DynamicEventObject{};
    class DEF_PARTICLE_VOLCANO_DE: DynamicEventObject{};
};

    //* Sounds for events on spawns
class CfgSoundsets
{
    class WaterStream_SoundSet;
    class HeliCrash_Distant_Base_SoundSet;

    class Dummy_Silent_SoundSet: HeliCrash_Distant_Base_SoundSet
    {
        soundShaders[] = {"Dummy_Silent_SoundShader"};
    };

    class Shipwreck_SoundSet: HeliCrash_Distant_Base_SoundSet
    {
        soundShaders[] = {"Shipwreck_SoundShader"};
    };

    class PlaneCrash_Distant_SoundSet: HeliCrash_Distant_Base_SoundSet
    {
        soundShaders[] = {"PlaneCrash_Distant_SoundShader"};
    };

    class BoatWaves_SoundSet: WaterStream_SoundSet
    {
        soundShaders[] = {"BoatWaves_SoundShader"};
		rangeCurve="Smooth1Curve";
    };

    class BoatCreakingDeck_SoundSet: WaterStream_SoundSet
    {
        soundShaders[] = {"BoatCreakingDeck_SoundShader"};
		rangeCurve="Smooth1Curve";
    };
};

    //* Use sets not shaders...
class CfgSoundshaders
{
	class Dummy_Silent_SoundShader
	{
		samples[] = {{"dynamiceventframework\def_structures\data\sounds\environment\silentdummy", 1}};
		volume = 0.0;
		range = 0;
	};

    class Shipwreck_SoundShader
	{
		samples[] = {{"dynamiceventframework\def_structures\data\sounds\environment\shipHorn_2", 1}};
		volume = 2.00;
		range = 3000;
	};

    class BoatWaves_SoundShader
	{
		samples[]= {
                        {"dynamiceventframework\def_structures\data\sounds\environment\ambient\water\boat_waves", 1},
                        {"dynamiceventframework\def_structures\data\sounds\environment\ambient\water\boat_waves_2", 1}
                   };
		volume= 1.0;
		range=7;
	};

    class BoatCreakingDeck_SoundShader
	{
		samples[]= {{"dynamiceventframework\def_structures\data\sounds\environment\ambient\water\creaking-deck", 1}};
		volume= 1.0;
		range=11;
	};
};