class DEF_ContaminatedArea_Shipwreck_DE: DEF_ContaminatedArea_DE
{
    override void EEInit()
    {
        EEInit_SkipThis();          //? Skip double zone creation → would be done by InitializeArea() in super class
        InitializeArea(80, 15, 4); 	//? Radius, posHeight, negHeight
    };
};