from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from time import sleep
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys

driver = webdriver.Firefox()
url = "https://www.instahyre.com/candidate/opportunities/?company_size=0&job_functions=%2Fapi%2Fv1%2Fjob_function%2F10&job_type=0&search=true&years=3"
driver.get(url)

i=0;
while(True):
    try:
        if(i==0):
            # Find the email input field and enter the email address
            email_input = driver.find_element(By.ID, "email")
            email_input.clear()  # Clear any existing text in the input field
            email_input.send_keys("sahilamin219@gmail.com")

            # Find the password input field and enter the password
            password_input = driver.find_element(By.ID, "password")
            password_input.clear()  # Clear any existing text in the input field
            password_input.send_keys("Sahil@123")

            # Find and click the login button
            login_button = driver.find_element(By.CLASS_NAME, "btn-success")
            login_button.click()
            sleep(2)
            # _type = driver.find_element(By.ID, "job-functions-selectized")
            # _type.send_keys("Backend Development")
            # _type.send_keys(Keys.ENTER)

            exp = driver.find_element(By.ID, "years")
            exp.clear()  # Clear any existing text in the input field
            exp.send_keys("2")

            show_Result = driver.find_element(By.CLASS_NAME, "show-results")
            show_Result.click()

            # Click the first button
            first_button = WebDriverWait(driver, 8).until(
                EC.element_to_be_clickable((By.ID, "interested-btn"))
            )
            first_button.click()
        
        # print("\n\n First button clicked successfully!\n\n ")

        # Wait for the second button to be clickable
        second_button = WebDriverWait(driver, 8).until(
            EC.element_to_be_clickable((By.CLASS_NAME, "new-btn"))
        )
        
        # Click the second button
        second_button.click()
        # print("\n\n Second button clicked successfully!\n\n")

    finally:
        # Close the WebDriver
        # driver.quit()
        # exit()
        print(i);i+=1;
