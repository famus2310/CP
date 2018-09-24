import math
import itertools

def euler491():
    """Solution for problem 491."""
    # A number is divisible by 11 if and only the difference between the sum
    # of the digits of odd index and the sum of the digits of even index is
    # divisible by 11.
    # A solution is to generate all distinct combinations of 10 digits and
    # after checking that it leads to a difference divisible by 11, compute
    # the corresponding contribution.
    # For each distinct comb c, if comp is the complement of c in double-pand,
    # contribution is :
    # C = number_of_valid_perm(c) * number_of_valid_perm(comp)
    #   = nb_perm_with_rep_without_lead_0(c) * nb_perm_with_rep(comp)
    #     len(c) - nb(0, c)       len(c) !        len(comb) !
    #   = ----------------- * ----------------- * ------------------
    #           len(c)        prod(multipli_c!)   prod(multipl_comp!)
    # because each elements appears at most twice and number of dup in
    #  c is the number of dup in comp
    #      nb(non-0, c) * (len(c) - 1) ! * len(c) !
    # C =  ----------------------------------------
    #        2 ^ (2 * nb_duplicates(c))
    pand = list(range(10))
    s = 2 * sum(pand)
    comb_len = len(pand)
    prod_fact = math.factorial(comb_len) * math.factorial(comb_len - 1)
    total = 0
    # Next 6 lines are just a tedious but efficient way to generate distinct
    # combinations. "for c in itertools.combinations(numbers, comb_len):"
    # would work too but would need to have duplicates removed (with a set for
    # instance). However, it would be pretty tedious to adapt if the format
    # was to ever change.
    # It first selects the distinct digits that are used, then add the
    # duplicates.
    for l in range(comb_len + 1):  # first 5 iterations are pointless but...
        nb_dup = comb_len - l
        pow_two = 2 ** (2 * nb_dup)
        for dist_dig in itertools.combinations(pand, l):
            for dup in itertools.combinations(dist_dig, nb_dup):
                c = dist_dig + dup
                if (2 * sum(c) - s) % 11 == 10:
                    total += len([x for x in c if x]) * prod_fact // pow_two
    return total

print(euler491())