class DEF_ContaminatedArea_Shipwreck_DE: DEF_ContaminatedArea_DE
{
    override void EEInit()
    {
        EEInit_SkipThis();          //? Skip double zone creation → would be done by InitializeArea() in super class
        InitializeArea(5, 10, 10); 	//? Radius, posHeight, negHeight
    }
}

class DEF_ContaminatedArea_ShipwreckSmall_DE: DEF_ContaminatedArea_DE
{
    override void EEInit()
    {
        EEInit_SkipThis();          //? Skip double zone creation → would be done by InitializeArea() in super class
        InitializeArea(3, 5, 5); 	//? Radius, posHeight, negHeight
    }
}