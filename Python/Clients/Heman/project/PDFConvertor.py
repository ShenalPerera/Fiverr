import sys
import PyPDF2
import pandas as pd
import os
import time
import re
import re

from PyQt5.QtWidgets import (
    QApplication, QMessageBox, QMainWindow, QLabel, QPushButton,
    QFileDialog, QVBoxLayout, QWidget, QTextEdit, QLineEdit
)


class PdfToExcelConverter(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("PDF to Excel Converter")
        self.setGeometry(100, 100, 500, 300)  # Increased window size

        # Create main widget and layout
        main_widget = QWidget(self)
        self.setCentralWidget(main_widget)
        layout = QVBoxLayout()

        # Add heading label with style
        heading_label = QLabel("PDF TO EXCEL", self)
        heading_label.setStyleSheet("font-size: 20px; font-weight: bold;")
        layout.addWidget(heading_label)

        # Add label to display selected PDF file
        self.pdf_file_label = QLabel("", self)
        layout.addWidget(self.pdf_file_label)
        self.quiz_title_input = QLineEdit(self)
        self.quiz_content_input = QLineEdit(self)
        self.quiz_category_input = QLineEdit(self)
        self.quiz_tags_input = QLineEdit(self)
        self.category_input = QLineEdit(self)

        # Add labels for input fields
        layout.addWidget(QLabel("Quiz Title:", self))
        layout.addWidget(self.quiz_title_input)
        layout.addWidget(QLabel("Quiz Content:", self))
        layout.addWidget(self.quiz_content_input)
        layout.addWidget(QLabel("Quiz Category:", self))
        layout.addWidget(self.quiz_category_input)
        layout.addWidget(QLabel("Quiz Tags:", self))
        layout.addWidget(self.quiz_tags_input)
        layout.addWidget(QLabel("Category:", self))
        layout.addWidget(self.category_input)

        # Add select PDF button with style
        select_pdf_button = QPushButton("Select PDF File", self)
        select_pdf_button.setStyleSheet("font-size: 14px; background-color: #4CAF50; color: white;")
        select_pdf_button.clicked.connect(self.select_pdf)
        layout.addWidget(select_pdf_button)

        # Add convert and download button with style
        convert_button = QPushButton("Convert and Download", self)
        convert_button.setStyleSheet("font-size: 14px; background-color: #008CBA; color: white;")
        convert_button.clicked.connect(self.convert_to_excel)
        layout.addWidget(convert_button)

        # Set layout
        main_widget.setLayout(layout)

        # Initialize attributes
        self.selected_pdf_path = None
        self.excel_file_path = None

    def select_pdf(self):
        options = QFileDialog.Options()
        options |= QFileDialog.ReadOnly

        pdf_file_path, _ = QFileDialog.getOpenFileName(
            self, "Select PDF File", "", "PDF Files (*.pdf)", options=options
        )

        if pdf_file_path:
            self.selected_pdf_path = pdf_file_path
            self.pdf_file_label.setText(f"Selected PDF: {pdf_file_path}")
            print(f"Selected PDF: {pdf_file_path}")

    def convert_to_excel(self):
        self.clear_report_file()
        if self.selected_pdf_path:
            pdf_file_path = self.selected_pdf_path
            print("Converting PDF into Excel.....")

            # Open the PDF file and extract text
            with open(pdf_file_path, "rb") as pdf_file:
                pdf_reader = PyPDF2.PdfReader(pdf_file)  # Replace PdfFileReader with PdfReader
                extracted = []
                for page_num in range(len(pdf_reader.pages)):  # Use len(pdf_reader.pages) instead of numPages
                    page = pdf_reader.pages[page_num]  # Use pages instead of getPage
                    page_text = page.extract_text()  # Use extract_text() instead of extractText()
                    extracted.extend(page_text.split("\n"))

            # Define column names
            columns = [
                "Quiz Title", "Quiz Content", "Quiz Category", "Quiz Tags", "Question",
                "Category", "Multi-Question Category", "Title", "Total Point",
                "Show points In Box", "Answer 1", "Point 1", "Answer 2", "Point 2",
                "Answer 3", "Point 3", "Answer 4", "Point 4", "Answer",
                "Different points for each answer", "Answer points diff modus activated",
                "Question text", "Message with correct answer", "Message with incorrect answer",
                "Hint", "Materials", "Certificate awarded for", "Passing percentage",
                "Course", "Lesson or topic", "Certificate"
            ]

            # Create a DataFrame
            df = pd.DataFrame(columns=columns)

            # Manually assign data to specific columns based on extracted lines
            skip = -1
            allData = []
            current_question = {}
            allData = []  # This list will store all your questions

            skip = -1  # Initialize skip to -1

            # to detect next question start
            next_question = True
            extracted_lines = []
            for i in extracted:
                line = re.sub(r'\\x00|\\x0|\\x000|\\x0000', '', i)
                line = self.clean_text(line)

                extracted_lines.append(line)
            for i, line in enumerate(extracted_lines):
                if (i < len(extracted_lines) - 1):
                    line = self.clean_text(line)
                    try:

                        if i <= skip:
                            continue

                        match = re.search(r'(?i)question\s*#?(\d+)', line)
                        if match:
                            allData.append(current_question)
                            current_question = {}
                            current_question['Quiz Title'] = self.quiz_title_input.text()
                            current_question['Quiz Content'] = self.quiz_content_input.text()
                            current_question['Quiz Category'] = self.quiz_category_input.text()
                            current_question['Quiz Tags'] = self.quiz_tags_input.text()
                            current_question['Category'] = self.category_input.text()
                            question_number = match.group(1)
                            question_number = "Question " + str(question_number)
                            current_question = {column: "" for column in columns}
                            # Found a question number
                            current_question['Question'] = 'multiple'
                            current_question['Title'] = question_number
                            self.log_test_result(question_number, "Sucessfully fetched into Excel.")
                            print("Fetching " + question_number + " into Excel")
                            current_question['Total point'] = 1
                            ques = i + 1
                            questionText = ""
                            while not extracted_lines[ques].startswith('A.'):
                                skip = ques
                                questionText += extracted_lines[ques] + '\n'
                                ques += 1
                            current_question['Question Text'] = questionText
                            next_question = False

                        elif current_question:
                            if line.startswith("A."):
                                option1 = line
                                ques = i + 1
                                while not extracted_lines[ques].startswith('B.'):
                                    skip = ques
                                    option1 += extracted_lines[ques] + '\n'
                                    ques += 1
                                current_question['Answer 1'] = self.clean_text(option1)
                            if line.startswith("B."):
                                option2 = line
                                ques = i + 1
                                while not extracted_lines[ques].startswith('C.'):
                                    skip = ques
                                    option2 += extracted_lines[ques] + '\n'
                                    ques += 1
                                current_question['Answer 2'] = self.clean_text(option2)
                            if line.startswith("C."):
                                option3 = line
                                ques = i + 1
                                while not extracted_lines[ques].startswith('D.'):
                                    skip = ques
                                    option3 += extracted_lines[ques] + '\n'
                                    ques += 1
                                current_question['Answer 3'] = self.clean_text(option3)
                            if line.startswith("D."):
                                option4 = line
                                # ques = i + 1
                                # while not (extracted_lines[ques].startswith('Correct Answer:')) or (extracted_lines[ques].startswith('Answer:')):
                                #     skip = ques
                                #     option4 += extracted_lines[ques] + '\n'
                                #     ques += 1
                                current_question['Answer 4'] = self.clean_text(option4)

                            if line.startswith("Correct Answer:") or line.startswith('Answer'):
                                # Found the correct answer
                                try:
                                    current_question["Correct Answer"] = line.split(":")[1].strip()
                                except:
                                    current_question["Correct Answer"] = line.split(" ")[1].strip()
                            elif re.search(r'(?i)Reference\s*', line):
                                # Found the Explanation/Reference
                                option1 = ""
                                ques = i + 1
                                while ques < len(extracted_lines) and not extracted_lines[ques].startswith('QUESTION'):
                                    option1 += extracted_lines[ques] + '\n'
                                    ques += 1

                                current_question["Message with correct answer"] = self.clean_text(option1)

                    except Exception as e:
                        self.log_test_result(question_number, str(e))
                        continue

            # Now, allData contains your processed da   ta, and the code won't fail due to index errors.

            df = pd.DataFrame(allData)

            # Export DataFrame to Excel
            base_filename = "quiz_data"
            extension = "xlsx"
            counter = 1
            base_filename = "quiz_data"
            extension = "xlsx"
            counter = 1

            while True:
                filename, _ = QFileDialog.getSaveFileName(
                    self, "Save Excel File", f"{base_filename}_{counter}.{extension}", "Excel Files (*.xlsx)"
                )

                if filename:
                    if not filename.endswith(".xlsx"):
                        filename += ".xlsx"

                    if not os.path.exists(filename):
                        break  # Exit the loop if the filename is unique

                    counter += 1

            if filename:
                df.to_excel(filename, index=False, engine="openpyxl")
                self.excel_file_path = filename
                print(f"Conversion to Excel completed successfully. Saved as {filename}")

                # Inform user about successful conversion
                msg_box = QMessageBox()
                msg_box.setIcon(QMessageBox.Information)
                msg_box.setText("Conversion to Excel completed successfully.")
                msg_box.setWindowTitle("Conversion Complete")
                msg_box.exec_()
            else:
                msg_box = QMessageBox()
                msg_box.setIcon(QMessageBox.Information)
                msg_box.setText("Conversion to Excel was canceled.")
                msg_box.setWindowTitle("Conversion Canceled")
                msg_box.exec_()
        else:
            msg_box = QMessageBox()
            msg_box.setIcon(QMessageBox.Information)
            msg_box.setText("Select PDF file first")
            msg_box.setWindowTitle("No PDF Selected")
            msg_box.exec_()

    def clean_text(self, text):
        # Remove illegal characters from the text
        import string
        clean_text = re.sub(r'[\\/*?[\]:]', '', str(text))
        clean_text = ''.join(filter(lambda x: x in string.printable, clean_text))
        cleaned_string = re.sub(r'[\x00-\x1F\x7F-\x9F]', '', clean_text)
        return cleaned_string

        return clean_text

    def closeEvent(self, event):
        if self.excel_file_path and os.path.exists(self.excel_file_path):
            os.remove(self.excel_file_path)
        event.accept()

    def log_test_result(self, question, status, error=None):
        # current_time = time.strftime("%Y-%m-%d %H:%M:%S")
        with open("convert_logs", 'a') as f:
            f.write(f"\nQuestion:  '{question}' \nQuestion Status:  {status}")
            if error:
                f.write(f" - {error}")
            f.write("\n")

    def clear_report_file(self):
        with open("convert_logs", 'w') as f:
            f.write("Test Report:\n")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = PdfToExcelConverter()
    window.show()
    sys.exit(app.exec_())
