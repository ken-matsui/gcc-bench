import os
import re
from collections import namedtuple
import matplotlib.pyplot as plt

Trait = namedtuple('Trait', [
    'before_time',
    'after_time',
    'before_peak_mem',
    'after_peak_mem',
    'before_total_mem',
    'after_total_mem'
])

def parse_markdown(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    print(f'Parsing {file_path} ...')

    # Grab the last block (assuming there's at least one)
    blocks = re.split(r'\n## ', content)
    last_block = blocks[-1]

    data = []
    for line in last_block.split('\n'):
        if line.startswith('x  10') or line.startswith('+  10'):
            data.append(float(line.split()[5]))

        if (len(data) == 6):
            break

    before_time, after_time, before_peak_mem, after_peak_mem, before_total_mem, after_total_mem = data

    return Trait(before_time, after_time, before_peak_mem, after_peak_mem, before_total_mem, after_total_mem)

def plot_bar_chart(hash_map, attribute_before, attribute_after, title, output_filename):
    keys = sorted(hash_map.keys())

    before_values = [getattr(hash_map[key], attribute_before) for key in keys]
    after_values = [getattr(hash_map[key], attribute_after) for key in keys]

    bar_width = 0.75
    spacing = 2
    index = range(0, int(spacing * len(keys)), int(spacing))

    fig, ax = plt.subplots()

    bar1 = ax.bar(index, before_values, bar_width, label='W/o built-in', alpha=0.8)
    bar2 = ax.bar([i+bar_width for i in index], after_values, bar_width, label='With built-in', alpha=0.8)

    ax.set_title(title)
    ax.set_xticks([i + bar_width / 2 for i in index])
    ax.set_xticklabels(keys, rotation=90, ha='right')
    ax.tick_params(axis='x', which='major', labelsize=8)
    ax.legend()

    plt.tight_layout()
    plt.savefig(os.path.join('reports', output_filename))


def main():
    file_map = {}

    for filename in os.listdir():
        if filename.endswith('.md') and filename != "README.md":
            trait_name = os.path.splitext(filename)[0]
            file_map[trait_name] = parse_markdown(filename)

    plot_bar_chart(file_map, 'before_time', 'after_time', 'Time Improvements', 'time.png')
    plot_bar_chart(file_map, 'before_peak_mem', 'after_peak_mem', 'Peak Memory Improvements', 'peak_mem.png')
    plot_bar_chart(file_map, 'before_total_mem', 'after_total_mem', 'Total Memory Improvements', 'total_mem.png')


if __name__ == '__main__':
    main()
