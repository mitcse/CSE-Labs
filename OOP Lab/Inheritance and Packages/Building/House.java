package com.course.buildings;

import java.util.*;

public class House extends Building {

	int nBeds;
	int nBaths;
	
	public void setBed (int nBeds) {
		this.nBeds = nBeds;
	}

	public void setBath (int nBaths) {
		this.nBaths = nBaths;
	}	
	
	public int getBed () {
		return nBeds;
	}

	public int getBath () {
		return nBaths;
	}

}
