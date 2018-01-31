#!/usr/bin/python

# Ce scrypt permet de calculer les parametre de definition d'un type
# a virgule fixe en fonction de la range (min max) souhaitee et du
# pas. NE FONCTIONNE QUE POUR LES TYPES SIGNEE.
# les formules sont tiree de la documentation des types a virgule
# fixe de mentor graphics.

import sys, math

def get_command_line_params(argv):
    """ Handles the arguments for using command line with inputs """
    def usage():
        print("USAGE : python params_ac_fixed.py <min> <max> <pas>")
    if len(argv) != 3 :
        usage();
        sys.exit(2)
    params = [float(arg) for arg in argv]
    if params[0] > params[1] :
        print("ERROR : min > max")
        sys.exit(2)
    if params[2] > (params[1] - params[0]) :
        print("ERROR : pas > max-min")
        sys.exit(2)
    return params

def compute_params(min_p, max_p, pas):
    """ computes the parameters and gives I and W
        to define a ac_fixed type
    """
    # Determining parameters
    if min_p == 0.0 :
        i = math.log((max_p + pas), 2)
        signed = False
    else :
        i = math.log((-2 * min_p), 2)
        signed = True
    w = i - math.log(pas, 2)
    i = round(i)
    w = round(w)
    # Determining the real range and step
    if signed :
        low = -0.5 * math.pow(2, i)
        high = (0.5 - math.pow(2, -w)) * math.pow(2, i)
        display_type = "signed"
    else :
        low = 0.0
        high = (1 - math.pow(2, -w)) * math.pow(2, i)
        display_type = "unsigned"
    step = math.pow(2, (i-w))
    i = int(i)
    w = int(w)
    # Displaying results
    print("=== Parameters for ac_fixed {0} type ===".format(display_type))
    print("             [ I = {0}, W = {1} ]".format(i,w))
    print("(gives a range from {0} to {1} with steps of {2})".format(low, high, step))

if __name__ == '__main__':
    params = get_command_line_params(sys.argv[1:])
    compute_params(params[0], params[1], params[2])
