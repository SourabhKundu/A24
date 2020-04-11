<!DOCTYPE html>
<html lang="en">

<head>
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@500&display=swap" rel="stylesheet">
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">

    <!-- jQuery library -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>

    <!-- Latest compiled JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="style.css">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Find IT!
    </title>
</head>

<body>
    <div id="main">
        <h1>Job Portal</h1>
        <form action="index.php" method="POST">
            <div class="form__group field">
                <input id="type" type="input" class="form__field" placeholder="Skill Here!" name="skill" id='skill' required /> <br><br>
                <input type="submit" id="subb" style="margin-left: -2px;" name="sub" class="btn btn-primary">
            </div>
        </form>
    </div>
    <div id="result" class="container">
        <?php
        if (isset($_POST["sub"])) {
            $temp = 0;
            function function_alert($message)
            {
                echo "<script>document.getElementById('result').innerHTML = '<h2>No result</h2>';</script>";
            }
            $skill = $_POST['skill'];

            $conn = mysqli_connect("localhost", "root", "", "mydata");

            if (!$conn) {
                die("Connection failed: " . mysqli_connect_error());
            }

            $sql = 'SELECT * FROM job';
            $result = mysqli_query($conn, $sql);
            if (mysqli_num_rows($result) > 0) {
                echo '<table class="table">';
                echo '<thead>
                <tr>
                    <th scope="col">Job</th>
                    <th scope="col">Company</th>
                    <th scope="col">Address</th>
                    <th scope="col">Package</th>
                    <th scope="col">Recomnded Skills</th>
                </tr>
            </thead>';
                while ($row = mysqli_fetch_assoc($result)) {
                    $alls = strtolower($row['skill']);
                    $us=strtolower($skill);
                    if (preg_match("/{$us}/i", $alls)) {
                        $temp++;
                        echo ' <tr>
                        <td>' . $row["profile"] . '</td>
                        <td>' . $row["company"] . '</td>
                        <td>' . $row["addresss"] . '</td>
                        <td>' . $row["pac"] . '</td>
                        <td>' . $row["skill"] . '</td>
                    </tr>';
                    }
                   
                }
                if($temp==0)
                {
                    function_alert('error');
                }
                echo "</table>";
            } else {
                echo "edo";
            }
        }
        ?>
    </div>

</body>

</html>