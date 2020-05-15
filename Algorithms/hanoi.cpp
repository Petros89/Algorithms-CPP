#include <map>
#include <string>
#include <list>
#include <cassert>
#include <cstdio>

// 0 is the bottom position of each peg, could be empty.

using disk_t = unsigned int;

static std::list<disk_t> peg_a;
static std::list<disk_t> peg_b;
static std::list<disk_t> peg_c;

enum peg_t { A = 'A', B = 'B', C = 'C' };

const disk_t max_disk = 4;
std::map<peg_t, std::list<disk_t>> pegs = {
    {A, {4, 3, 2, 1}},
    {B, {}},
    {C, {}}
};

static void hanoi_move(peg_t src, peg_t dst, int d) {
    std::string indent(d, '-');

    disk_t picked_up = pegs[src].back();
    printf("%s Moving %d from %c to %c\n", indent.c_str(), picked_up, src, dst);

    pegs[src].pop_back();
    pegs[dst].push_back(picked_up);
}

static void hanoi_move_stack(disk_t disk, peg_t src, peg_t dst, peg_t aux, int d) {
    assert(src != dst && dst != aux); // auxiliary
    std::string indent(d, '-');

    printf("%s Trying to move disks %d...1 from %c to %c\n", 
        indent.c_str(), 
        disk, src, dst);

    if (disk == 1) {
        hanoi_move(src, dst, d + 1);
    } else {
        hanoi_move_stack(disk - 1, src, aux, dst, d + 1);
        hanoi_move(src, dst, d + 1);
        hanoi_move_stack(disk - 1, aux, dst, src, d + 1);
    }
}

void hanoi_print() {
    for (const peg_t &peg : {A, B, C}) {
        printf("%c: ", peg);
        for (disk_t &disk : pegs[peg]) {
            printf("%d ", disk);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    printf("Initial state:\n");
    hanoi_print();
    
    hanoi_move_stack(max_disk, A, C, B, 0);

    printf("Final state:\n");
    hanoi_print();
}