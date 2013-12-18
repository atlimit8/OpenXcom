/*
 * Copyright 2010-2013 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#define _USE_MATH_DEFINES
#include "City.h"
#include <math.h>

namespace OpenXcom
{

/**
 * Initializes a city with certain data.
 * @param name Name of the city.
 * @param lon Longitude of the city.
 * @param lat Latitude of the city.
 */
City::City(const std::string &name, double lon, double lat): _name(name), _lon(lon), _lat(lat)
{
}

/**
 *
 */
City::~City()
{
}

/**
 * Loads the region type from a YAML file.
 * @param node YAML node.
 */
void City::load(const YAML::Node &node)
{
	_name = node["name"].as<std::string>(_name);
	_lon = node["lon"].as<double>(_lon) * M_PI / 180;
	_lat = node["lat"].as<double>(_lat) * M_PI / 180;
}

/**
 * Saves the region type to a YAML file.
 * @return YAML node.
 */
YAML::Node City::save(const std::string &name) const
{
	YAML::Node node;
	node["name"] = name;
	node["lon"] = _lon * 180 / M_PI;
	node["lat"] = _lat * 180 / M_PI;
	return node;
}

/**
 * Returns the name of the city.
 * @return The city's name.
 */
std::string City::getName() const
{
	return _name;
}

/**
 * Returns the latitude coordinate of the city.
 * @return The city's latitude in radians.
 */
double City::getLatitude() const
{
	return _lat;
}

/**
 * Returns the longitude coordinate of the city.
 * @return The city's longitude in radians.
 */
double City::getLongitude() const
{
	return _lon;
}

}
