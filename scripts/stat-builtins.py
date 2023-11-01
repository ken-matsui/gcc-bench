import os
import sys


def calculate_improvement_percentage(old, new):
    """
    Calculate the improvement percentage.
    """
    return ((old - new) / old) * 100


def calculate_average_for_category(directory, category):
    """
    Calculate average improvement for a specific category within a directory.
    """
    builtin_file_path = os.path.join(directory, f"{category}_builtin.txt")
    no_builtin_file_path = os.path.join(directory, f"{category}_no_builtin.txt")

    with open(builtin_file_path, "r") as f_builtin, open(
        no_builtin_file_path, "r"
    ) as f_no_builtin:
        builtin_values = list(map(float, f_builtin.readlines()))
        no_builtin_values = list(map(float, f_no_builtin.readlines()))

    total_improvement_percentage = 0.0
    for builtin, no_builtin in zip(builtin_values, no_builtin_values):
        total_improvement_percentage += calculate_improvement_percentage(
            no_builtin, builtin
        )

    return total_improvement_percentage / len(builtin_values)


def main():
    categories = ["time", "peak_mem", "total_mem"]
    base_directory = "./reports/builtins/"

    improvements = {category: {} for category in categories}
    total_improvements = {category: 0.0 for category in categories}
    num_directories = 0

    for builtin in os.listdir(base_directory):
        path = os.path.join(base_directory, builtin)

        # Check if it's a directory and contains the expected txt files
        if os.path.isdir(path) and all(
            os.path.exists(os.path.join(path, f"{category}_builtin.txt"))
            for category in categories
        ):
            num_directories += 1

            for category in categories:
                avg = calculate_average_for_category(path, category)
                improvements[category][builtin] = avg
                total_improvements[category] += avg

    print("Best 3 Improvements:")
    for category in categories:
        print(f"  {category}:")
        for builtin, improvement in sorted(
            improvements[category].items(), key=lambda x: x[1], reverse=True
        )[:3]:
            print(f"    {builtin}: {improvement:.2f}%")
        print()

    print("Overall Averages:")
    for category in categories:
        print(f"  {category}: {total_improvements[category] / num_directories:.2f}%")

    if len(sys.argv) > 1 and sys.argv[1] == "--all":
        print()
        print("All Improvements:")
        for category in categories:
            print(f"  {category}:")
            for builtin, improvement in sorted(
                improvements[category].items(), key=lambda x: x[1], reverse=True
            ):
                print(f"    {builtin}: {improvement:.2f}%")


if __name__ == "__main__":
    main()
