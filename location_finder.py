import sys
from geopy.geocoders import Nominatim
def get_current_location():
    try:
        loc = ''
        for i in sys.argv:
            if i == 'location_finder.py':
                continue
            loc += ' '+i
        geolocator = Nominatim(user_agent="nearest_hospitals_app")
        location = geolocator.geocode(loc)
        if location:
            return location.latitude, location.longitude
        else:
            print("Failed to retrieve current location.")
            return None, None
    except Exception as e:
        print("Error fetching current location:", str(e))
        return None, None
latitude, longitude = get_current_location()
if latitude is not None and longitude is not None:
    print(latitude)
    print(longitude)
else:
    print("Could not determine current location.")