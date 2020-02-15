def detect_collisions(balls):
    """ 
    Detect any pairs of balls that are colliding.
    Returns a set of ball_pairs.
    """

    set_of_collisions = set()

    bins = {}

    for ball in balls:
        i = int((ball.x - world_min_x) // 256)
        j = int((ball.y - world_min_y) // 256)
        if ((i, j) in bins):
            bins[(i, j)].append(ball)
        else:
            bins[(i, j)] = [ball]

    for bin in bins:
        for i in range(len(bins[bin]) - 1):
            for j in range(i + 1, len(bins[bin])):
                if (colliding(bins[bin][i], bins[bin][j])):
                    set_of_collisions.add(
                        ball_pair(bins[bin][i], bins[bin][j]))
            if ((bin[0], bin[1] + 1) in bins):
                for j in range(len(bins[(bin[0], bin[1] + 1)])):
                    if (colliding(bins[bin][i], bins[(bin[0],
                                                      bin[1] + 1)][j])):
                        set_of_collisions.add(
                            ball_pair(bins[bin][i], bins[(bin[0],
                                                          bin[1] + 1)][j]))
            if ((bin[0] + 1, bin[1]) in bins):
                for j in range(len(bins[(bin[0] + 1, bin[1])])):
                    if (colliding(bins[bin][i], bins[(bin[0] + 1,
                                                      bin[1])][j])):
                        set_of_collisions.add(
                            ball_pair(bins[bin][i], bins[(bin[0] + 1,
                                                          bin[1])][j]))
            if ((bin[0] + 1, bin[1] + 1) in bins):
                for j in range(len(bins[(bin[0] + 1, bin[1] + 1)])):
                    if (colliding(bins[bin][i], bins[(bin[0] + 1,
                                                      bin[1] + 1)][j])):
                        set_of_collisions.add(
                            ball_pair(bins[bin][i], bins[(bin[0] + 1,
                                                          bin[1] + 1)][j]))

    return set_of_collisions


import gas
