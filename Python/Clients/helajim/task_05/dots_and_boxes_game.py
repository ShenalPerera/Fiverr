from box import Box


class DotsAndBoxesGame:
    TIE = "tie"
    PLAYER1 = "A"
    PLAYER2 = "B"

    def __init__(self, grid_width, grid_height, player_name_1, player_name_2):
        self.__grid_width = grid_width
        self.__grid_height = grid_height
        self.__player_name_1 = player_name_1
        self.__player_name_2 = player_name_2
        self.__grid = self.create_grid()

    def create_grid(self):
        grid = []
        for row in range(self.__grid_height):
            temp_row = []
            for col in range(self.__grid_width):
                box = Box()
                temp_row.append(box)
            grid.append(temp_row)
        return grid

    def add_line(self, x, y, side, player):
        box = self.__grid[x - 1][y - 1]
        isBoxMarked = False
        if box.add_line(side):
            self.update_neighbour_of_box(x - 1, y - 1, side)

            if box.four_lines_placed():
                box.add_owner(DotsAndBoxesGame.PLAYER1 if player == self.__player_name_1 else DotsAndBoxesGame.PLAYER2)
                isBoxMarked = True
            neighbour_box = self.get_neighbour_on_side(side, x - 1, y - 1)
            if neighbour_box is not None and neighbour_box.four_lines_placed():
                neighbour_box.add_owner(
                    DotsAndBoxesGame.PLAYER1 if player == self.__player_name_1 else DotsAndBoxesGame.PLAYER2)
                isBoxMarked = True

            if isBoxMarked:
                return True, True
            return True, False
        return False, False

    def update_neighbour_of_box(self, row_index, column_index, side):
        neighbour_box = self.get_neighbour_on_side(side, row_index, column_index)
        if neighbour_box is not None:
            if side == Box.LEFT:
                neighbour_box.add_line(Box.RIGHT)
            elif side == Box.RIGHT:
                neighbour_box.add_line(Box.LEFT)
            elif side == Box.UP:
                neighbour_box.add_line(Box.DOWN)
            elif side == Box.DOWN:
                neighbour_box.add_line(Box.UP)

    def get_neighbour_on_side(self, side, row_index, column_index):

        MIN_ROW_INDEX = 0
        MAX_ROW_INDEX = self.__grid_height - 1
        MIN_COL_INDEX = 0
        MAX_COL_INDEX = self.__grid_width - 1

        if side == Box.LEFT and column_index > MIN_COL_INDEX:
            return self.__grid[row_index][column_index - 1]
        elif side == Box.RIGHT and column_index < MAX_COL_INDEX:
            return self.__grid[row_index][column_index + 1]
        elif side == Box.UP and row_index > MIN_ROW_INDEX:
            return self.__grid[row_index - 1][column_index]
        elif side == Box.DOWN and row_index < MAX_ROW_INDEX:
            return self.__grid[row_index + 1][column_index]
        else:
            return None

    def calculate_points_of_player(self, player):
        points = 0
        for row in self.__grid:
            for box in row:
                if box.get_owner() == player:
                    points += 1

        return points

    def is_ended(self):
        for row in self.__grid:
            for box in row:
                if box.get_owner() is None:
                    return False
        return True

    def winner(self):
        player1_points = self.calculate_points_of_player(DotsAndBoxesGame.PLAYER1)
        player2_points = self.calculate_points_of_player(DotsAndBoxesGame.PLAYER2)

        if player1_points > player2_points:
            return self.__player_name_1
        elif player2_points > player1_points:
            return self.__player_name_2
        else:
            return DotsAndBoxesGame.TIE

    def give_score(self):
        player1_points = self.calculate_points_of_player(DotsAndBoxesGame.PLAYER1)
        player2_points = self.calculate_points_of_player(DotsAndBoxesGame.PLAYER2)

        string = "\nScore:\n\n"
        string += f"{(self.__player_name_1 + f' ({DotsAndBoxesGame.PLAYER1})').ljust(15)} | {(self.__player_name_2 + f' ({DotsAndBoxesGame.PLAYER2})').ljust(15)}\n"
        string += "-" * 37
        string += "\n"
        string += f"{str(player1_points).ljust(15)} | {str(player2_points).ljust(15)}\n"
        return string

    def one_rwo_of_grid(self, row_index):
        string = ""

        if row_index == 0:
            row = self.__grid[row_index]
        elif row_index == self.__grid_height * 2:
            row = self.__grid[self.__grid_height - 1]
        else:
            row = self.__grid[row_index // 2]

        if row_index % 2 == 0:

            string += "   o"
            for box in row:
                if row_index != self.__grid_height * 2:
                    if box.has_line_on_side(Box.UP):
                        string += " __ o"
                    else:
                        string += "    o"
                elif row_index == self.__grid_height * 2:
                    if box.has_line_on_side(Box.DOWN):
                        string += " __ o"
                    else:
                        string += "    o"

        else:
            for i, box in enumerate(row):
                if box.has_line_on_side(Box.LEFT) and i == 0:
                    string += "|"
                elif i == 0:
                    string += " "
                if box.has_line_on_side(Box.RIGHT):
                    if box.four_lines_placed():
                        string += f" {box.get_owner()}  |"
                    else:
                        string += f"    |"
                else:
                    string += "     "
        string += "\n"
        return string

    def __str__(self):
        string = "   "
        for col in range(1, self.__grid_width + 1):
            string += f"   {col} "

        string += '\n'

        row_number = 1

        for row in range(0, self.__grid_height * 2 + 1):
            if row % 2 == 1:
                string += f"{row_number}  "
                row_number += 1
            string += self.one_rwo_of_grid(row)

        string += self.give_score()
        return string
