class Fan:
    # Class attributes
    def __init__(self, brand, circumference, height):
        self.brand = brand
        self.circumference = circumference
        self.height = height
        self.degrees = 0
        self.speeds = ["off", "low", "medium", "high"]
        self.speed = "off"

    def set_speed(self, speed):
        if speed in self.speeds:
            self.speed = speed
        else:
            print("Invalid speed.")

    def set_degrees(self, degrees):
        if degrees < 0:
            print("Invalid degrees.")
            self.degrees = 0
        elif degrees > 360:
            self.degrees = degrees % 360
        else:
            self.degrees = degrees

    def get_degrees(self):
        return self.degrees

    def get_speed(self):
        return self.speed

    def get_brand(self):
        return self.brand

    def get_circumference(self):
        return self.circumference

    def get_height(self):
        return self.height
