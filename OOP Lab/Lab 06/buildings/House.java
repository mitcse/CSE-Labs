package buildings;
import java.util.*;

class House extends Building
{
	int nBeds;
	int nBaths;
	void setBed(int nBeds)
	{
		this.nBeds = nBeds;
	}

	void setBath(int nBaths)
	{
		this.nBaths = nBaths;
	}	
	
	int getBed()
	{
		return nBeds;
	}

	int getBath()
	{
		return nBaths;
	}

}
