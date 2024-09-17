def time_to_solve(level, diff, time_cur, time_prev):
    if level >= diff:
        return time_cur
    return (diff - level) * (time_cur + time_prev) + time_cur

def solution(diffs, times, limit):
    def calculate_total_time(level):
        total = 0
        prev_time = 0
        for diff, time_cur in zip(diffs, times):
            total += time_to_solve(level, diff, time_cur, prev_time)
            prev_time = time_cur
        return total

    min_level, max_level = 1, max(diffs)

    while min_level < max_level:
        mid_level = (min_level + max_level) // 2
        if calculate_total_time(mid_level) <= limit:
            max_level = mid_level
        else:
            min_level = mid_level + 1

    return min_level
