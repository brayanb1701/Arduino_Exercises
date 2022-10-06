<?php 
//-- variables para conectarse a la base de datos
$servidor   = 'localhost';
$base_datos = 'boton_arduino';
$tabla  = 'pulsadores';
$usr_sistema    = 'root';
$pass_sistema   = 'alumnos1'; 
//-- Conexion a la Base de datos segun variables declaradas 
//$conexion=mysql_connect($servidor, $usr_sistema, $pass_sistema);

$con=mysqli_connect($servidor, $usr_sistema, $pass_sistema, $base_datos);

date_default_timezone_set('America/Bogota');
//-- Captura de las variables del formulario.
$fecha = date("Y-m-d");
$hora = date("H:i:s");

 
// Leemos los valores que nos llegan por GET
$maquina = mysqli_real_escape_string($con, $_GET['maquina']);
$boton = mysqli_real_escape_string($con, $_GET['boton']);
    // Esta es la instrucción para insertar los valores
$query = "INSERT INTO ".$tabla."(maquina,boton,fecha,hora) "
."VALUES('$maquina','$boton','$fecha','$hora')"; 


 mysqli_query($con, $query);
    mysqli_close($con);





?>
