package buildings;
import java.util.*;

class Building
{
	float sqft;
	int stories;

	void setFeet(float sqft)
	{
		this.sqft = sqft;
	}

	void setStories(int stories)
	{
		this.stories = stories;
	}

	int getStories()
	{
		return stories;
	}

	float getFeet()
	{
		return sqft;
	}

}
