'''
A template for a python script deliverable for INST326.

Driver: Awani Bayisa
Navigator: Felipe Martinez
Assignment: Template INST326
Date: 3_10_22

Challenges Encountered: ~~~~~~~~~~~
'''

class Appointment:
    '''
        Appointment: Class have name, start,end attributes
    '''
    def __init__(self, name, start, end):
        '''

        :param name: Name of the appointment object
        :param start: This is tuple consisting of two integers representing the start time of the appointment. The first
                      integer represents an hour in 24-hour time; the second integer represents a number of minutes.
                      For example, the tuple (10, 30) would represent 10:30 am
        :param end:  a tuple similar to start representing the end time of the appointment.
        '''
        self.name = name
        self.start = start
        self.end = end

    def overlaps(self, other):
        '''

        :param other: An Object of the Appointment class
        :return:  True the start time of one appointment occurs between the start and end times of the other
                  appointment (including if the start times are equal), OR
                 • the end time of one appointment occurs between the start and end times of the other
                    appointment (including if the end times are equal)
                 False : Otherwise
        '''
        return self.start <= other.start < self.end or self.start < other.end <= self.end
