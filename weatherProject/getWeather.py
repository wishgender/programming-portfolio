# -*- coding: utf-8 -*-
from bs4 import BeautifulSoup
import requests
import re
import datetime
# from datetime import datetime, timedelta
# import random
import metpy.calc as mpcalc
from metpy.units import units

startHour=18
endHour=22

# def getRandomTime(startHour, endHour):
#     startTime = datetime.combine(datetime.today(), datetime.min.time()) + timedelta(hours=startHour)
#     endTime = datetime.combine(datetime.today(), datetime.min.time()) + timedelta(hours=endHour)

#     randomSeconds=random.randint(int((endTime - startTime).total_seconds()), 0)
#     randomTime=startTime + timedelta(seconds=randomSeconds)
#     return randomTime

current_date=datetime.datetime.now().strftime("%Y-%m-%d_%H.%M")
degreeIndex=-1

KentOH_URL = "https://www.wunderground.com/weather/us/oh/kent"
AthensGA_URL = "https://www.wunderground.com/weather/us/ga/athens"
SeattleWA_URL = "https://www.wunderground.com/weather/us/wa/seattle"
PhoenixAZ_URL = "https://www.wunderground.com/weather/us/az/phoenix"

class City:
    def __init__(self, URL, cityName):
        self.cityURL = URL
        self.cityName = cityName

athensGA=City(AthensGA_URL, "Athens, GA")
kentOH=City(KentOH_URL, "Kent, OH")
seattleWA=City(SeattleWA_URL, "Seattle, WA")
phoenixAZ=City(PhoenixAZ_URL, "Phoenix, AZ")


directions= [
    ["N", "north"],
    ["S", "south"],
    ["E", "east"],
    ["W", "west"],
    [r"\s+", "whitespace"],
    [r"\d+", "number"]
]

class weatherInfo:
    def __init__(self, location):
        self.location = location
        self.timestamp = ""
        self.currentTemp = ""
        self.hiTemp = ""
        self.loTemp = ""
        self.pressureIn = ""
        self.skyCondition = ""
        self.windDir = ""
        self.windSpeed = ""
        self.humidity = ""
        self.rainfall = ""
        self.snowfall = ""

for pattern in directions:
    pattern[0] = re.compile(pattern[0]) 

def getDirection(chars):
    degrees=re.search(r"\d+",chars).group(0)
    angle_deg=degrees*units('degree')
    retVal=mpcalc.angle_to_direction(angle_deg)
    return retVal

def removeDegree(string):
    degreeIndex=string.index('\xa0')
    newString=string[:degreeIndex]
    return newString

def getWeather(City):
    session=requests.session()
    req=session.get(City.cityURL)
    doc=BeautifulSoup(req.content,features="lxml")
    
    location = City.cityName
    weather = weatherInfo(location)
    weather.timestamp=doc.find('p', {"class" : "timestamp"}).get_text()
    
    weather.currentTemp=doc.find('div', {"class" : "current-temp"}).get_text()
    weather.hiTemp=doc.find('span', {"class" : "hi"}).get_text()
    weather.loTemp=doc.find('span', {"class" : "lo"}).get_text()
    
    pressureIn=doc.find('lib-display-unit', {"type" : "pressure"}).get_text()
    weather.pressureIn = removeDegree(pressureIn)+'\"'

    humidity=doc.find('lib-display-unit', {"type" : "humidity"}).get_text()
    weather.humidity= removeDegree(humidity)+'%'
    
    rainfall=doc.find('lib-display-unit', {"type" : "rain"}).get_text()
    weather.rainfall=removeDegree(rainfall)+'\"'

    snowfall=doc.find('lib-display-unit', {"type" : "snow"}).get_text()
    weather.snowfall=removeDegree(snowfall)+'\"'
    
    weather.skyCondition=doc.find('div', {"class" : "condition-icon small-6 medium-12 columns"}).get_text()

    wind=doc.find('div', {"class" : "wind-compass"}).get("style")
    weather.windSpeed = doc.find('header', {"class" : "wind-speed"}).get_text() + " mph "
    weather.windDir = getDirection(wind)
    return weather

def writeFile(weather):
    fileName=f"weatherData/{current_date}_{weather.location}.txt"
    with open(fileName, "w") as f:
        f.write("\n\nCurrent date & time: ")
        f.write(weather.timestamp)
        f.write("\nLocation: ")
        f.write(weather.location)
        f.write("\nCurrent Temperature: ")
        f.write(weather.currentTemp)
        f.write("\nMaximum temperature: ")
        f.write(weather.hiTemp)
        f.write("\nMinimum temperature: ")
        f.write(weather.loTemp)
        f.write("\nPressure: ")
        f.write(weather.pressureIn)
        f.write("\nSky conditions: ")
        f.write(weather.skyCondition)
        f.write("\nWind: ")
        f.write(weather.windSpeed + "from " + weather.windDir)
        f.write("\nHumidity: ")
        f.write(weather.humidity)
        f.write("\nRainfall: ")
        f.write(weather.rainfall)
        f.write("\nSnow Depth: ")
        f.write(weather.snowfall)
        print("Weather Data for " + weather.location + " saved to file ", fileName, "\n")


# randomTime=getRandomTime(startHour,endHour)
# Athens, GA
writeFile(getWeather(athensGA))
writeFile(getWeather(kentOH))
writeFile(getWeather(seattleWA))
writeFile(getWeather(phoenixAZ))

