class CfgModels
{
	class Default
	{
		sections[] = {};
		sectionsInherit="";
		skeletonName = "";
	};
	class ambulance_flipped:Default
	{
		sections[]=
		{
			"body",
			"bottom",
			"lights",
			"dashboard",
			"wheels",
			"plate"
		};
	};
};