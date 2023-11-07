import unittest

from fan import Fan


class FanTest(unittest.TestCase):

    def test_init(self):
        fan = Fan("Dyson", 120, 18)
        self.assertEqual(fan.brand, "Dyson")
        self.assertEqual(fan.circumference, 120)
        self.assertEqual(fan.height, 18)
        self.assertEqual(fan.degrees, 0)
        self.assertEqual(fan.speed, "off")

    def test_set_speed(self):
        fan = Fan("Dyson", 120, 18)
        fan.set_speed("low")
        self.assertEqual(fan.speed, "low")
        fan.set_speed("medium")
        self.assertEqual(fan.speed, "medium")
        fan.set_speed("high")
        self.assertEqual(fan.speed, "high")
        fan.set_speed("off")
        self.assertEqual(fan.speed, "off")
        fan.set_speed("invalid")
        self.assertEqual(fan.speed, "off")

    def test_set_degrees(self):
        fan = Fan("Dyson", 120, 18)
        fan.set_degrees(180)
        self.assertEqual(fan.degrees, 180)
        fan.set_degrees(-180)
        self.assertEqual(fan.degrees, 0)
        fan.set_degrees(360)
        self.assertEqual(fan.degrees, 360)
        fan.set_degrees(540)
        self.assertEqual(fan.degrees, 180)

    def test_get_degrees(self):
        fan = Fan("Dyson", 120, 18)
        fan.set_degrees(180)
        self.assertEqual(fan.get_degrees(), 180)
        fan.set_degrees(-180)
        self.assertEqual(fan.get_degrees(), 0)
        fan.set_degrees(360)
        self.assertEqual(fan.get_degrees(), 360)
        fan.set_degrees(540)
        self.assertEqual(fan.get_degrees(), 180)

    def test_get_speed(self):
        fan = Fan("Dyson", 120, 18)
        fan.set_speed("low")
        self.assertEqual(fan.get_speed(), "low")
        fan.set_speed("medium")
        self.assertEqual(fan.get_speed(), "medium")
        fan.set_speed("high")
        self.assertEqual(fan.get_speed(), "high")
        fan.set_speed("off")
        self.assertEqual(fan.get_speed(), "off")

    def test_get_brand(self):
        fan = Fan("Dyson", 120, 18)
        self.assertEqual(fan.get_brand(), "Dyson")

    def test_get_circumference(self):
        fan = Fan("Dyson", 120, 18)
        self.assertEqual(fan.get_circumference(), 120)

    def test_get_height(self):
        fan = Fan("Dyson", 120, 18)
        self.assertEqual(fan.get_height(), 18)


if __name__ == "__main__":
    unittest.main()
