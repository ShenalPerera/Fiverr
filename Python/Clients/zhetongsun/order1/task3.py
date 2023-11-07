import math

"""
    p(t) = p0 * e^(r *t)
    p = 3602 * e ^(r *t)

    5137 = 3602 * e ^(r*10)
    e^10r = 1.4261

    ln(e^10r) = ln(1.4261)
    10r = 0.3549
    r = 0.03549
    
"""


def population(initial_count, time, r):
    return initial_count * math.exp(r * time)


def get_time(initial, value, r):
    return (math.log((value / float(initial)), math.e)) / r


def round_half_up(n, decimals=0):
    multiplier = 10 ** decimals
    return math.floor(n * multiplier + 0.5) / multiplier


print(f"After 30 years population is {int(round_half_up(population(3602, 30, 0.03549)))}")
print(f"Required time is: {get_time(3602, 100, 0.03549)}")
